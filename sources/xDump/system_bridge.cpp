#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QUrl>

#include "config_parser.h"
#include "system_bridge.h"

namespace xDump {

void SystemBridge::transferToParser(QString file, QString section){
    parser.parseConfig(file, section);
}

QString SystemBridge::executeCommand(QString execName, QStringList arguments)
{
    return executer.runCommand(execName, arguments);
}

QString SystemBridge::wrapFileUrl (QUrl fileUrl)
{
    return fileUrl.toLocalFile();
}

}
