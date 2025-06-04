#include "servercore.h"
#include <openssl/evp.h>  
#include <QRandomGenerator>
#include "../../crypto/crypto_util.h"


bool ServerCore::createServer(const QHostAddress &address, quint16 port, const QString &rootUserName, const QString &password) {
    // 获取当前工作目录
    QString currentDir = QDir::currentPath();
    QString certPath = currentDir + QDir::separator() + "serverCert.pem";
    QString keyPath = currentDir + QDir::separator() + "serverKey.pem";

    if (!generateCertAndKey(certPath, keyPath)) {
        qDebug() << "Failed to set SSL certificate and key!";
        return false;
    }

    if (!server.loadServerCertificates(certPath, keyPath)) {
        qDebug() << "Failed to load SSL certificate and key!";
        return false;
    }

    if (!createDatabase(rootUserName, password)) {
        qDebug() << "Database connection failed!";
        return false;
    }

    // 检查格式是否正确
    if(!address.isNull() && port > 0) {
        qDebug() << "正在创建服务端...";
    } else {
        qDebug() << "IP地址或端口号格式错误！";
        return false;
    }
    if (!server.listen(address, port)) {
        qDebug() << "Server listen failed!";
        return false;
    }
    serverAddress = address;
    serverPort = port;
    qDebug() << "Server listen on " << serverAddress.toString() << ":" << serverPort;

    return true;
}

bool ServerCore::generateCertAndKey(const QString &certPath, const QString &keyPath) {
    QFileInfo certFileInfo(certPath);
    QFileInfo keyFileInfo(keyPath);

    // 检查证书和密钥文件是否都存在，不存在则生成
    if (!(certFileInfo.exists() && keyFileInfo.exists())) {
        // Python 脚本的路径
        QString scriptResourcePath = ":/scripts/generatecertandkey.py";

        // 读取资源中的脚本内容
        QFile scriptFile(scriptResourcePath);
        if (!scriptFile.open(QIODevice::ReadOnly))
            return false;

        QTextStream in(&scriptFile);
        QString scriptContent = in.readAll();
        scriptFile.close();

        // 创建临时文件
        QTemporaryFile tempFile;
        if (!tempFile.open())
            return false;

        // 写入脚本内容到临时文件
        QTextStream out(&tempFile);
        out << scriptContent;
        tempFile.close();

        // 创建 QProcess 实例
        QProcess *process = new QProcess;

        // 启动 Python 解释器执行临时脚本文件
        process->start("python", QStringList() << tempFile.fileName());

        // 等待执行完成，或设置一个超时
        if (!process->waitForFinished(3000)) return false;
    }

    return certFileInfo.isFile() && certFileInfo.isReadable() &&
           keyFileInfo.isFile() && keyFileInfo.isReadable();
}

bool ServerCore::createDatabase(const QString &rootUserName, const QString &password) {
    // 创建数据库（设置引擎）
    db = QSqlDatabase::addDatabase("QSQLITE");
    // 获取当前工作目录
    QString currentDir = QDir::currentPath();
    // 构建数据库文件的路径，这里假设你要保存的数据库文件名为mydatabase.db
    QString databasePath = currentDir + QDir::separator() + "server_db.db";
    qDebug() << "Database saved in " << databasePath;
    // 设置数据库保存路径
    db.setDatabaseName(databasePath);
    if (!db.open()) return false;
    qDebug() << "Database connection successful!!";

    QSqlQuery query;
    // 创建用户表user
    query.exec(
        "CREATE TABLE IF NOT EXISTS user ("
        "u_id    INT PRIMARY KEY,"              // user id
        "u_name  VARCHAR(20) UNIQUE NOT NULL,"  // user name
        "pw      VARCHAR(64) NOT NULL,"         // 64位SM3十六进制串
        "salt    VARCHAR(64) NOT NULL,"         // 盐
        "su_t    DATETIME,"                     // sign up time
        "sd_t    DATETIME,"                     // sign down time
        "role    VARCHAR(5) NOT NULL);"         // user role ('root', 'admin', 'user')
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建聊天室表chatroom
    query.exec(
        "CREATE TABLE IF NOT EXISTS chatroom ("
        "c_id    INT PRIMARY KEY,"              // chatroom id
        "c_name  VARCHAR(20) UNIQUE NOT NULL,"  // chatroom name
        "c_u_id  INT NOT NULL,"                 // creator user id
        "cr_t    DATETIME,"                     // creation time
        "ds_t    DATETIME);"                    // dissolution time
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建用户-聊天室关系表user_chatroom
    query.exec(
        "CREATE TABLE IF NOT EXISTS user_chatroom ("
        "u_id    INT NOT NULL,"                 // user id
        "c_id    INT NOT NULL,"                 // chatroom id
        "j_t     DATETIME,"                     // join time
        "q_t     DATETIME,"                     // quit time
        "role    VARCHAR(5) NOT NULL,"          // user role in chatroom ("root", "admin", "user")
        "PRIMARY KEY(u_id, c_id),"
        "FOREIGN KEY(u_id) REFERENCES user(u_id),"
        "FOREIGN KEY(c_id) REFERENCES chatroom(c_id));"
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建消息表message
    query.exec(
        "CREATE TABLE IF NOT EXISTS message ("
        "m_id    INT PRIMARY KEY,"              // message id
        "m_u_id  INT NOT NULL,"                 // user id
        "m_c_id  INT NOT NULL,"                 // chatroom id
        "m_t     DATETIME,"                     // message time
        "m_db_t  DATETIME,"                     // message drawback time
        "m_text  TEXT,"                         // message text
        "FOREIGN KEY(m_u_id) REFERENCES user(u_id),"
        "FOREIGN KEY(m_c_id) REFERENCES chatroom(c_id));"
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器，限制用户名长度
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_u_name_length "
        "BEFORE INSERT ON user "
        "FOR EACH ROW "
        "WHEN LENGTH(NEW.u_name) < 1 OR LENGTH(NEW.u_name) > 20 "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'u_name must be between 1 and 20 characters'); "
        "END; "
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器，限制密码长度
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_pw_length "
        "BEFORE INSERT ON user "
        "FOR EACH ROW "
        "WHEN LENGTH(NEW.pw) < 64 OR LENGTH(NEW.pw) > 64 "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'pw must be between 6 and 20 characters'); "
        "END; "
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器强制要求密码包含数字、字母
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_pw_format "
        "BEFORE INSERT ON user "
        "FOR EACH ROW "
        "WHEN NEW.pw NOT GLOB '*[0-9]*' OR NEW.pw NOT GLOB '*[a-zA-Z]*' "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'pw must contain at least one number and one letter'); "
        "END; "
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器，限制用户角色
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_role_value "
        "BEFORE INSERT ON user "
        "FOR EACH ROW "
        "WHEN NEW.role NOT IN ('root', 'admin', 'user') "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'role must be one of: root, admin, user'); "
        "END; "
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器，root超级管理员不能被删除
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_root "
        "BEFORE DELETE ON user "
        "FOR EACH ROW "
        "WHEN OLD.role = 'root' "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'root user cannot be deleted'); "
        "END; "
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器，聊天室名长度限制1-20个字符之间
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_c_name_length "
        "BEFORE INSERT ON chatroom "
        "FOR EACH ROW "
        "WHEN LENGTH(NEW.c_name) < 1 OR LENGTH(NEW.c_name) > 20 "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'c_name must be between 1 and 20 characters'); "
        "END; "
        );
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    // 创建触发器，用户注册时间不能晚于注销时间
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_u_t "
        "BEFORE INSERT ON user "
        "FOR EACH ROW "
        "WHEN NEW.su_t > NEW.sd_t "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'su_t must be earlier than sd_t'); "
        "END; "
        );

    // 创建触发器，聊天室创建时间不能晚于注销时间
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_c_t "
        "BEFORE INSERT ON chatroom "
        "FOR EACH ROW "
        "WHEN NEW.cr_t > NEW.ds_t "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'cr_t must be earlier than ds_t'); "
        "END; "
        );

    // 创建触发器，消息发送时间不能晚于撤回时间
    query.exec(
        "CREATE TRIGGER IF NOT EXISTS check_m_t "
        "BEFORE INSERT ON message "
        "FOR EACH ROW "
        "WHEN NEW.m_t > NEW.m_db_t "
        "BEGIN "
        "   SELECT RAISE(FAIL, 'm_t must be earlier than m_db_t'); "
        "END; "
        );

    query.exec("SELECT MAX(u_id) FROM user;");
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (query.next())
        maxUserNumber = query.value(0).toInt(); // 获取用户号最大值

    query.exec("SELECT MAX(c_id) FROM chatroom;");
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (query.next())
        maxChatroomNumber = query.value(0).toInt(); // 获取聊天室号最大值

    query.exec("SELECT MAX(m_id) FROM message;");
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (query.next())
        maxMessageNumber = query.value(0).toInt(); // 获取消息号最大值

    // 如果不存在超级管理员，则创建超级管理员账号(role="root")
    if (registerAccount(rootUserName, password, "root")) {
        adminUserID = maxUserNumber;    // 设置当前管理员用户ID
        qDebug() << "超级管理员账号创建成功!";
    } else {
        // 若存在超级管理员，验证密码是否正确
       query.exec(QString("SELECT u_id, pw, salt FROM user WHERE u_name='%1' AND role='root';").arg(rootUserName));
        if (!query.next()) {
            qDebug() << "超级管理员不存在!";
            return false;
        }
        QString dbHash = query.value(1).toString();
        QString salt = query.value(2).toString();
        QString inputHash = hashPasswordWithSalt(password, salt);
        if (dbHash != inputHash) {
            qDebug() << "超级管理员密码错误!";
            return false;
        }
        adminUserID = query.value(0).toInt(); // 设置当前管理员用户ID
    }

    adminUserName = rootUserName;           // 设置当前管理员用户名
    qDebug() << "当前管理员用户ID:" << adminUserID << ";用户名:" << adminUserName;

    userTableModel = new QSqlTableModel;
    userTableModel->setTable("user"); // 替换为你的表名
    userTableModel->select(); // 执行查询以加载数据
    userTableModel->setHeaderData(0, Qt::Horizontal, "用户ID");
    userTableModel->setHeaderData(1, Qt::Horizontal, "用户名");
    userTableModel->setHeaderData(2, Qt::Horizontal, "哈希值");  // pw
    userTableModel->setHeaderData(3, Qt::Horizontal, "盐");      // salt
    userTableModel->setHeaderData(4, Qt::Horizontal, "注册时间");
    userTableModel->setHeaderData(5, Qt::Horizontal, "注销时间");
    userTableModel->setHeaderData(6, Qt::Horizontal, "用户角色");

    chatTableModel = new QSqlTableModel;
    chatTableModel->setTable("chatroom"); // 替换为你的表名
    chatTableModel->select(); // 执行查询以加载数据
    chatTableModel->setHeaderData(0, Qt::Horizontal, "聊天室ID");
    chatTableModel->setHeaderData(1, Qt::Horizontal, "聊天室名");
    chatTableModel->setHeaderData(2, Qt::Horizontal, "创建者用户ID");
    chatTableModel->setHeaderData(3, Qt::Horizontal, "创建时间");
    chatTableModel->setHeaderData(4, Qt::Horizontal, "解散时间");

    return true;
}

bool ServerCore::registerAccount(const QString &userName, const QString &password, const QString &role) {
    QSqlQuery query;

    // 检查用户名是否已存在
    query.exec(QString("SELECT u_name FROM user WHERE u_name = '%1';").arg(userName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (query.next()) {
        qDebug() << "用户名已存在!";
        return false;
    }

    // 插入新用户
    QString salt = generateSalt();
    QString hash = hashPasswordWithSalt(password, salt);
    QString sql = QString(
        "INSERT INTO user (u_id, u_name, pw, salt, su_t, sd_t, role) "
        "VALUES (%1,'%2','%3','%4','%5',%6, '%7');")
        .arg(++maxUserNumber)
        .arg(userName)
        .arg(hash)
        .arg(salt)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
        .arg("NULL")
        .arg(role);

    // 执行SQL语句
    query.exec(sql);
    if (query.lastError().isValid()) {
        --maxUserNumber;
        qDebug() << query.lastError();
        return false;
    }
    // 更新界面显示的用户表
    if (userTableModel){
        userTableModel->select();
    }

    return true;
}

bool ServerCore::loginAccount(QSslSocket *socket, const QString &userName, const QString &password) {
    QSqlQuery query;

    // 检查用户名是否已存在
    query.exec(QString("SELECT u_name FROM user WHERE u_name = '%1' AND sd_t IS NULL;").arg(userName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    query.next();
    if (query.value(0).toString().isEmpty()) {
        qDebug() << "用户名不存在!";
        return false;
    }

    // 检查密码是否正确
    // query.exec(QString("SELECT pw FROM user WHERE u_name = '%1';").arg(userName));
    // if (query.lastError().isValid()) {
    //     qDebug() << query.lastError();
    //     return false;
    // }
    // query.next();
    // if (query.value(0).toString() != password) {
    //     qDebug() << "密码错误!";
    //     return false;
    // }
    query.exec(QString("SELECT pw, salt FROM user WHERE u_name = '%1' AND sd_t IS NULL;").arg(userName));
    if (!query.next()) {
        qDebug() << "用户名不存在!";
        return false;
    }

    QString dbHash = query.value(0).toString();
    QString salt = query.value(1).toString();
    QString inputHash = hashPasswordWithSalt(password, salt);

    if (inputHash != dbHash) {
        qDebug() << "密码错误!";
        return false;
    }


    // 该账号与该连接绑定
    userSocketMap.insert(userName, socket);

    return true;
}

bool ServerCore::createChatroom(const QString &chatroomName, const QString &userName) {
    QSqlQuery query;

    // 检查聊天室名是否已存在
    query.exec(QString("SELECT c_id FROM chatroom WHERE c_name = '%1';").arg(chatroomName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (query.next()) {
        qDebug() << "聊天室名已存在!";
        return false;
    }

    // 检查用户名是否已存在
    query.exec(QString("SELECT u_id FROM user WHERE u_name = '%1' AND sd_t IS NULL;").arg(userName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (!query.next()) {
        qDebug() << "用户名不存在!";
        return false;
    }

    int userID = query.value(0).toInt();

    // 插入新聊天室和新用户-聊天室关系，以事务的方式执行，保证原子性
    query.exec("BEGIN;");
    query.exec(QString(
        "INSERT INTO chatroom (c_id, c_name, c_u_id, cr_t, ds_t) VALUES "
        "(%1,'%2',%3,'%4',%5);")
        .arg(++maxChatroomNumber)
        .arg(chatroomName)
        .arg(userID)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
        .arg("NULL"));
    query.exec(QString(
        "INSERT INTO user_chatroom (u_id, c_id, j_t, q_t, role) VALUES "
        "(%1,%2,'%3',%4, '%5');")
        .arg(userID)
        .arg(maxChatroomNumber)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
        .arg("NULL")
        .arg("root"));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        query.exec("ROLLBACK;");
        --maxChatroomNumber;
        return false;
    }
    query.exec("COMMIT;");

    // 更新界面显示的聊天室表
    if (chatTableModel){
        chatTableModel->select();
    }

    return true;
}

bool ServerCore::joinChatroom(const QString &chatroomName, const QString &userName) {
    QSqlQuery query;

    // 检查聊天室名是否已存在
    query.exec(QString("SELECT c_id FROM chatroom WHERE c_name = '%1' AND ds_t IS NULL;").arg(chatroomName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (!query.next()) {
        qDebug() << "聊天室名不存在!";
        return false;
    }

    int chatroomID = query.value(0).toInt();

    // 检查用户名是否已存在
    query.exec(QString("SELECT u_id FROM user WHERE u_name = '%1' AND sd_t IS NULL;").arg(userName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (!query.next()) {
        qDebug() << "用户名不存在!";
        return false;
    }

    int userID = query.value(0).toInt();

    // 插入新用户-聊天室关系
    query.exec(QString(
        "INSERT INTO user_chatroom (u_id, c_id, j_t, q_t, role) VALUES "
        "(%1,%2,'%3',%4,'%5');")
        .arg(userID)
        .arg(chatroomID)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
        .arg("NULL")
        .arg("user"));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

QJsonArray ServerCore::getJoinedChatList(const QString &userName) {
    QJsonArray chatList;
    QSqlQuery query;

    // 查询该用户已加入的所有聊天室
    query.exec(QString(
        "SELECT c_name FROM user_chatroom uc "
        "INNER JOIN chatroom c ON uc.c_id = c.c_id "
        "INNER JOIN user u ON uc.u_id = u.u_id "
        "WHERE u_name = '%1' AND q_t IS NULL AND ds_t IS NULL;")
        .arg(userName));
    if (query.lastError().isValid()) {
        qDebug() << "When getJoinedChatList: " << query.lastError();
        return chatList;
    }

    while (query.next()) {
        chatList.append(query.value(0).toString());
    }

    return chatList;
}

QJsonArray ServerCore::getUnjoinedChatList(const QString &userName) {
    QJsonArray chatList;
    QSqlQuery query;

    // 查询该用户未加入的所有聊天室
    query.exec(QString(
        "SELECT c_name FROM chatroom "
        "WHERE c_id NOT IN "
        "(SELECT uc.c_id FROM user_chatroom uc "
        "INNER JOIN chatroom c ON uc.c_id = c.c_id "
        "INNER JOIN user u ON uc.u_id = u.u_id "
        "WHERE u_name = '%1' AND q_t IS NULL AND ds_t IS NULL AND sd_t IS NULL) "
        "AND ds_t IS NULL;")
        .arg(userName));
    if (query.lastError().isValid()) {
        qDebug() << "When getUnjoinedChatList: " << query.lastError();
        return chatList;
    }

    while (query.next()) {
        chatList.append(query.value(0).toString());
    }

    return chatList;
}

QJsonArray ServerCore::getChatUserList(const QString &chatName) {
    QJsonArray userList;
    QSqlQuery query;

    // 查询该聊天室的所有用户
    query.exec(QString(
        "SELECT u_name FROM user_chatroom "
        "INNER JOIN chatroom ON user_chatroom.c_id = chatroom.c_id "
        "INNER JOIN user ON user_chatroom.u_id = user.u_id "
        "WHERE c_name = '%1' AND ds_t IS NULL AND sd_t IS NULL;")
        .arg(chatName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return userList;
    }

    while (query.next()) {
        userList.append(query.value(0).toString());
    }

    return userList;
}

QJsonArray ServerCore::getMessage(const QString &chatName, const int latestMessageID, const QString &lastTime) {
    QJsonArray messageList;
    QSqlQuery query;

    // 查询该聊天室 ID > latestMessageID 的所有消息（每条聊天记录包含id,name,content,time）
    query.exec(QString(
        "SELECT m_id, u_name, m_text, m_t FROM message "
        "INNER JOIN user ON message.m_u_id = user.u_id "
        "INNER JOIN chatroom ON message.m_c_id = chatroom.c_id "
        "WHERE c_name = '%1' AND m_id > %2 AND m_db_t IS NULL AND ds_t IS NULL "
        "ORDER BY message.m_t ASC;")
        .arg(chatName)
        .arg(latestMessageID));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return QJsonArray();
    }

    while (query.next()) {
        QJsonObject message;
        message.insert("id", query.value(0).toInt());
        message.insert("name", query.value(1).toString());
        message.insert("content", query.value(2).toString());
        message.insert("time", query.value(3).toString());
        messageList.append(message);
    }

    // 查询被撤回的消息
    query.exec(QString(
        "SELECT m_id FROM message "
        "INNER JOIN chatroom ON message.m_c_id = chatroom.c_id "
        "WHERE c_name = '%1' AND m_db_t IS NOT NULL AND m_db_t >= '%2' AND ds_t IS NULL;")
        .arg(chatName)
        .arg(lastTime));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return QJsonArray();
    }

    while (query.next()) {
        QJsonObject message;
        message.insert("id", query.value(0).toInt());
        message.insert("time", "");
        messageList.append(message);
    }

    return messageList;
}

bool ServerCore::sendMessage(const QString &chatName, const QString &senderName, const QString &message) {
    QSqlQuery query;

    // 查询该聊天室的 ID
    query.exec(QString(
        "SELECT c_id FROM chatroom WHERE c_name = '%1';")
        .arg(chatName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (!query.next()) {
        qDebug() << "聊天室不存在!";
        return false;
    }
    int chatID = query.value(0).toInt();

    // 查询该用户的 ID
    query.exec(QString(
        "SELECT u_id FROM user WHERE u_name = '%1' AND sd_t IS NULL;")
        .arg(senderName));
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
        return false;
    }
    if (!query.next()) {
        qDebug() << "用户不存在!";
        return false;
    }
    int senderID = query.value(0).toInt();

    // 插入消息 m_id, m_u_id, m_c_id, m_t, m_text
    query.exec(QString(
        "INSERT INTO message (m_id, m_u_id, m_c_id, m_t, m_db_t, m_text) "
        "VALUES (%1,%2,%3,'%4',%5,'%6');")
        .arg(++maxMessageNumber)
        .arg(senderID)
        .arg(chatID)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
        .arg("NULL")
        .arg(message));
    if (query.lastError().isValid()) {
        --maxMessageNumber;
        qDebug() << query.lastError();
        return false;
    }

    synchronizationRemind(chatName, senderName);

    return true;
}

bool ServerCore::synchronizationRemind(const QString &chatName, const QString &senderName) {
    return true;
    // 发送同步提醒消息，提醒聊天室中所有在线用户更新信息
    QJsonObject remindJsonObj = baseJsonObj("synchronization", "remind");

    // 编辑数据字段
    QJsonObject dataObj;
    dataObj["chatName"] = chatName;
    remindJsonObj["data"] = dataObj;

    // 发送消息给该聊天室的在线用户（从数据库中选出该聊天室用户，再用userSocketMap尝试发送）
    QJsonArray userList = getChatUserList(chatName);
    qDebug() << "发送同步提醒报文：" << userList;
    for (int i = 0; i < userList.size(); i++) {
        QString userName = userList.at(i).toString();
        if (userName == senderName) {   // 不给消息发送者发送同步提醒
            continue;
        }
        if (userSocketMap.contains(userName)) {
            sendJsonObj(userSocketMap[userName], remindJsonObj);
        }
    }

    return true;
}

void ServerCore::processReadMessage(QSslSocket *socket, const QString &message) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.toUtf8());
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        qDebug() << "数据报文解析失败!";
        return;
    }
    QJsonObject jsonObj = jsonDoc.object();

    if (jsonObj["state"].toString() != "request") {
        qDebug() << "该数据报文不是请求报文!";
        return;
    }

    QString type = jsonObj["type"].toString();
    QJsonObject dataObj = jsonObj["data"].toObject();

    if (type == "test") {
        if (dataObj["test"] == "test") {
            qDebug() << "测试成功";
            QJsonObject resJsonObj = baseJsonObj(type, "success");
            sendJsonObj(socket, resJsonObj);
        } else {
            qDebug() << "测试失败";
            QJsonObject resJsonObj = baseJsonObj(type, "failed");
            sendJsonObj(socket, resJsonObj);
            return;
        }
    } else if (type == "register") {
        QString user = dataObj["userName"].toString();
        if (registerAccount(user, dataObj["password"].toString(), dataObj["role"].toString())) {
            qDebug() << "新账号注册成功";
            logAudit("register", user, "新账号注册成功");

            QJsonObject resJsonObj = baseJsonObj(type, "success");
            QJsonObject resDataObj = resJsonObj["data"].toObject();
            resDataObj["userName"] = user;
            resJsonObj["data"] = resDataObj;
            sendJsonObj(socket, resJsonObj);
        } else {
            qDebug() << "新账号注册失败";
            logAudit("register_failed", user, "注册失败");
            QJsonObject resJsonObj = baseJsonObj(type, "failed");
            sendJsonObj(socket, resJsonObj);
            return;
        }
    } else if (type == "login") {
        QString user = dataObj["userName"].toString();
        if (loginAccount(socket, user, dataObj["password"].toString())) {
            qDebug() << "用户登录成功";
            logAudit("login", user, "登录成功");

            QJsonObject resJsonObj = baseJsonObj(type, "success");
            QJsonObject resDataObj = resJsonObj["data"].toObject();
            resDataObj["userName"] = user;
            resJsonObj["data"] = resDataObj;
            sendJsonObj(socket, resJsonObj);
        } else {
            qDebug() << "用户登录失败";
            logAudit("login_failed", user, "登录失败");
            QJsonObject resJsonObj = baseJsonObj(type, "failed");
            sendJsonObj(socket, resJsonObj);
            return;
        }
    } else if (type == "createChatroom") {
        QString creator = dataObj["creatorName"].toString();
        QString chatroom = dataObj["chatName"].toString();
        if (createChatroom(chatroom, creator)) {
            qDebug() << "创建聊天室成功";
            logAudit("createChatroom", creator, "创建聊天室 " + chatroom);

            QJsonObject resJsonObj = baseJsonObj(type, "success");
            QJsonObject resDataObj = resJsonObj["data"].toObject();
            resDataObj["chatName"] = chatroom;
            resJsonObj["data"] = resDataObj;
            sendJsonObj(socket, resJsonObj);
        } else {
            qDebug() << "创建聊天室失败";
            logAudit("createChatroom_failed", creator, "聊天室名: " + chatroom);
            QJsonObject resJsonObj = baseJsonObj(type, "failed");
            sendJsonObj(socket, resJsonObj);
            return;
        }
    } else if (type == "joinChatroom") {
        QString user = dataObj["userName"].toString();
        QString chatroom = dataObj["chatName"].toString();
        if (joinChatroom(chatroom, user)) {
            qDebug() << "加入聊天室成功";
            logAudit("joinChatroom", user, "加入聊天室 " + chatroom);

            QJsonObject resJsonObj = baseJsonObj(type, "success");
            QJsonObject resDataObj = resJsonObj["data"].toObject();
            resDataObj["chatName"] = chatroom;
            resDataObj["userName"] = user;
            resJsonObj["data"] = resDataObj;
            sendJsonObj(socket, resJsonObj);
        } else {
            qDebug() << "加入聊天室失败";
            logAudit("joinChatroom_failed", user, "聊天室名: " + chatroom);
            QJsonObject resJsonObj = baseJsonObj(type, "failed");
            sendJsonObj(socket, resJsonObj);
            return;
        }
    } else if (type == "getChatList") {
        QString user = dataObj["userName"].toString();
        QJsonArray joinedChatList = getJoinedChatList(user);
        QJsonArray unjoinedChatList = getUnjoinedChatList(user);

        qDebug() << "获取用户可访问的聊天室列表成功";
        QJsonObject resJsonObj = baseJsonObj(type, "success");

        QJsonObject resDataObj = resJsonObj["data"].toObject();
        resDataObj["userName"] = user;
        resDataObj["joinedChatList"] = joinedChatList;
        resDataObj["unjoinedChatList"] = unjoinedChatList;
        resJsonObj["data"] = resDataObj;

        sendJsonObj(socket, resJsonObj);
    } else if (type == "getChatUserList") {
        QString chatroom = dataObj["chatName"].toString();
        QJsonArray chatUserList = getChatUserList(chatroom);

        qDebug() << "获取聊天室用户列表成功";
        QJsonObject resJsonObj = baseJsonObj(type, "success");

        QJsonObject resDataObj = resJsonObj["data"].toObject();
        resDataObj["chatName"] = chatroom;
        resDataObj["chatUserList"] = chatUserList;
        resJsonObj["data"] = resDataObj;

        sendJsonObj(socket, resJsonObj);
    } else if (type == "getMessage") {
        QString chatroom = dataObj["chatName"].toString();
        QJsonArray messageList = getMessage(
            chatroom,
            dataObj["latestMessageID"].toInt(),
            dataObj["lastTime"].toString()
        );

        qDebug() << "获取聊天室消息成功";
        QJsonObject resJsonObj = baseJsonObj(type, "success");

        QJsonObject resDataObj = resJsonObj["data"].toObject();
        resDataObj["chatName"] = chatroom;
        resDataObj["latestMessageID"] = dataObj["latestMessageID"].toInt();
        resDataObj["lastTime"] = dataObj["lastTime"].toString();
        resDataObj["messageList"] = messageList;
        resJsonObj["data"] = resDataObj;

        sendJsonObj(socket, resJsonObj);
        qDebug() << "已发送聊天室消息到ip地址和端口" << socket->peerAddress().toString() << socket->peerPort();
    } else if (type == "sendMessage") {
        QString chatName = dataObj["chatName"].toString();
        QString senderName = dataObj["senderName"].toString();

        QByteArray encKey = QByteArray::fromBase64(dataObj["encKey"].toString().toUtf8());
        QByteArray cipherText = QByteArray::fromBase64(dataObj["cipherText"].toString().toUtf8());

        QByteArray sm4_key = sm2_decrypt_no_pass("server_priv_nopass.pem", encKey);
        if (sm4_key.isEmpty()) {
            qDebug() << "SM2 解密失败";
            return;
        }

        QByteArray plainText;
        if (!sm4_decrypt(sm4_key, cipherText, plainText)) {
            qDebug() << "SM4 解密失败";
            return;
        }

        qDebug() << "解密后的消息：" << plainText;

        if (sendMessage(chatName, senderName, QString::fromUtf8(plainText))) {
            qDebug() << "发送消息成功";
            logAudit("sendMessage", senderName, "发送消息到聊天室 " + chatName);

            QJsonObject resJsonObj = baseJsonObj(type, "success");
            QJsonObject resDataObj = resJsonObj["data"].toObject();
            resDataObj["chatName"] = chatName;
            resDataObj["senderName"] = senderName;
            resDataObj["message"] = QString::fromUtf8(plainText);
            resJsonObj["data"] = resDataObj;
            sendJsonObj(socket, resJsonObj);
        } else {
            qDebug() << "发送消息失败";
            logAudit("sendMessage_failed", senderName, "发送失败 - 聊天室 " + chatName);
            QJsonObject resJsonObj = baseJsonObj(type, "failed");
            sendJsonObj(socket, resJsonObj);
        }
    }
}


void ServerCore::onReceiveMessage(QSslSocket *socket, const QString &message) {
    // 如果包含多个报文，需要分割
    QStringList messageList = message.split("}{");

    for (int i = 0; i < messageList.size(); i++) {
        // 如果不是第一个报文，需要加上 {
        if (i != 0) {
            messageList[i] = "{" + messageList[i];
        }

        // 如果不是最后一个报文，需要加上 }
        if (i != messageList.size() - 1) {
            messageList[i] = messageList[i] + "}";
        }

        processReadMessage(socket, messageList[i]);
    }
}

ServerCore::ServerCore() {
    maxUserNumber = 0;
    maxChatroomNumber = 0;
    maxMessageNumber = 0;
    connect(&server, &Server::receiveMessage, this, &ServerCore::onReceiveMessage);
} // 私有构造函数，确保单例

ServerCore::~ServerCore() {
    if (userTableModel) delete userTableModel;
    if (chatTableModel) delete chatTableModel;
}

QJsonObject ServerCore::baseJsonObj(const QString &type, const QString &state) {
    // 创建一个 JSON 对象
    QJsonObject jsonObj;
    jsonObj["type"] = type;
    jsonObj["state"] = state;

    // 创建一个嵌套的JSON数据对象
    QJsonObject dataObj;
    jsonObj["data"] = dataObj;

    return jsonObj;
}

void ServerCore::sendJsonObj(QSslSocket *socket, const QJsonObject &jsonObj) {
    // 使用 QJsonDocument 生成 JSON 字符串，并发送报文
    QJsonDocument jsonDoc(jsonObj);
    QString message = jsonDoc.toJson(QJsonDocument::Compact);
//    qDebug() << "发送报文到ip地址和端口" << socket->peerAddress().toString() << socket->peerPort();
//    qDebug() << socket->write(message.toUtf8());
    server.sendMessage(socket, message);
}
QString ServerCore::generateSalt(int length) {
    const QString chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString salt;
    for (int i = 0; i < length; ++i) {
        salt += chars.at(QRandomGenerator::global()->bounded(chars.size()));
    }
    return salt;
}

QString ServerCore::hashPasswordWithSalt(const QString &password, const QString &salt) {
    QByteArray data = (salt + password).toUtf8();

    // 1. 创建并初始化 EVP_MD_CTX
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (!ctx) {
        qDebug() << "EVP_MD_CTX_new() 失败";
        return QString();
    }

    // 2. 从默认 provider 中获取 “SM3” 算法对象
    const EVP_MD *md = EVP_MD_fetch(NULL, "SM3", NULL);
    if (!md) {
        qDebug() << "EVP_MD_fetch(\"SM3\") 拿不到 SM3，请检查 OpenSSL 是否支持 SM3";
        EVP_MD_CTX_free(ctx);
        return QString();
    }

    // 3. 初始化摘要计算
    if (EVP_DigestInit_ex(ctx, md, NULL) != 1) {
        qDebug() << "EVP_DigestInit_ex 失败";
        EVP_MD_CTX_free(ctx);
        return QString();
    }

    // 4. 填充数据
    if (EVP_DigestUpdate(ctx, data.constData(), data.size()) != 1) {
        qDebug() << "EVP_DigestUpdate 失败";
        EVP_MD_CTX_free(ctx);
        return QString();
    }

    // 5. 完成计算并获取结果
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int outlen = 0;
    if (EVP_DigestFinal_ex(ctx, digest, &outlen) != 1) {
        qDebug() << "EVP_DigestFinal_ex 失败";
        EVP_MD_CTX_free(ctx);
        return QString();
    }
    EVP_MD_CTX_free(ctx);

    // outlen 应该是 32（SM3 输出长度），我们把前 outlen 字节转成十六进制串返回
    return QByteArray((const char*)digest, outlen).toHex();
}
