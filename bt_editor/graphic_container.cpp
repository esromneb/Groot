#include "graphic_container.h"
#include "utils.h"
#include "mainwindow.h"


#include <QSignalBlocker>
#include <QMenu>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QInputDialog>


GraphicContainer::GraphicContainer(std::shared_ptr<void> model_registry,
                                   QWidget *parent) :
    QObject(parent),
    
    _signal_was_blocked(true)
{












}

void GraphicContainer::lockEditing(bool locked)
{







}


void GraphicContainer::nodeReorder()
{
}

void GraphicContainer::zoomHomeView()
{


}

bool GraphicContainer::containsValidTree() const
{




    return true;
}

void GraphicContainer::clearScene()
{
}


void GraphicContainer::onPortValueDoubleClicked(QLineEdit *edit_value)
{
}



void GraphicContainer::loadSceneFromTree(const AbsBehaviorTree &tree)
{






}



void GraphicContainer::loadFromJson(const QByteArray &data)
{
}


