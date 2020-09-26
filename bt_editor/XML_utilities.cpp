#include "XML_utilities.hpp"
#include "utils.h"


#include <behaviortree_cpp_v3/xml_parsing.h>
#include <QMessageBox>
#include <QtDebug>
#include <QLineEdit>


NodeModel buildTreeNodeModelFromXML(const QDomElement& node)
{

    return {};
}



NodeModels ReadTreeNodesModel(const QDomElement &root)
{
    NodeModels models;

    return models;
}





bool VerifyXML(QDomDocument &doc,
   const std::vector<QString>& registered_ID,
   std::vector<QString>& error_messages)
{

    return true;
}



QDomElement writePortModel(const QString& port_name, const PortModel& port, QDomDocument& doc)
{
    QDomElement port_element;

    return port_element;
}
