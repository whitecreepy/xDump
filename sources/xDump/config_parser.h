#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <QDomNamedNodeMap>
#include <QJSEngine>

#include <error_handler.h>

namespace xDump {

class ConfigParser
{
public:
    ConfigParser(QJSEngine &_jsEngine) : jsEngine(_jsEngine) {}

    void parseConfig(QString inputFile = "");

private:
    class ConfigElementAttributes
    {
    public:
        ConfigElementAttributes() {}
        ConfigElementAttributes(QDomNamedNodeMap attributesMap);
        ConfigElementAttributes(ConfigElementAttributes parentAttributes, QDomNamedNodeMap attributesMap);
        QString qGetName ();
        QString qGetType ();
        QString qGetMethod ();
        void dump();

    private:
        QString name;
        QString type;
        QString method;
    };

    void parseXmlElements(QDomNode docElem, ConfigElementAttributes parentAttributes);
    void addXmlToJsEngine(ConfigElementAttributes attributes, QString text = "");
    bool checkObjectHierarchy(QStringList objectHierarchy);

    static QString defaultConfigFileName;
    QJSEngine &jsEngine;
};

}
#endif // CONFIG_PARSER_H
