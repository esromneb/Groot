#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSettings>
#include <QTextStream>
#include <QList>
#include <QMap>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QToolButton>
#include <QWidgetAction>
#include <QTreeWidgetItem>
#include <QSvgWidget>
#include <QShortcut>
#include <QTabBar>
#include <QXmlStreamWriter>
#include <QDesktopServices>
#include <QInputDialog>



#include "utils.h"
#include "XML_utilities.hpp"



#include "utils.h"

#include "ui_about_dialog.h"

// using QtNodes::DataModelRegistry;
// using QtNodes::FlowView;
// using QtNodes::FlowScene;
// using QtNodes::NodeGraphicsObject;
// using QtNodes::NodeState;

MainWindow::MainWindow(GraphicMode initial_mode, QWidget *parent) :
                                                                    QMainWindow(parent),
                                                                    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


void MainWindow::closeEvent(QCloseEvent *event)
{
   
}


GraphicContainer* MainWindow::createTab(const QString &name)
{
    if( _tab_info.count(name) > 0)
    {
        throw std::runtime_error(std::string("There is already a Tab named ") + name.toStdString() );
    }
    GraphicContainer* ti = new GraphicContainer( nullptr, this );
    _tab_info.insert( {name, ti } );

    

    

    
    

    

    connect( ti, &GraphicContainer::undoableChange,
            this, &MainWindow::onPushUndo );

    connect( ti, &GraphicContainer::undoableChange,
            this, &MainWindow::onSceneChanged );

    // connect( ti, &GraphicContainer::requestSubTreeExpand,
    //         this, &MainWindow::onRequestSubTreeExpand );

    connect( ti, &GraphicContainer::requestSubTreeCreate,
            this, &MainWindow::onCreateAbsBehaviorTree);

    connect( ti, &GraphicContainer::addNewModel,
            this, &MainWindow::onAddToModelRegistry);

    return ti;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionLoad_triggered()
{

}

QString MainWindow::saveToXML() const
{
    return "";
}

QString MainWindow::xmlDocumentToString(const QDomDocument &document) const
{
return "";
}




void MainWindow::on_actionSave_triggered()
{
}

void MainWindow::onAutoArrange()
{
}

void MainWindow::onSceneChanged()
{

}


GraphicContainer* MainWindow::currentTabInfo()
{
    int index = ui->tabWidget->currentIndex();
    QString tab_name = ui->tabWidget->tabText(index);
    return getTabByName(tab_name);
}

GraphicContainer *MainWindow::getTabByName(const QString &tab_name)
{
    auto it = _tab_info.find( tab_name );
    return (it != _tab_info.end()) ? (it->second) : nullptr;
}


void MainWindow::lockEditing(bool locked)
{
    for(auto& tab_it: _tab_info)
    {
        tab_it.second->lockEditing(locked);
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    
    
    
    
    
    
    
    
    
    
    
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    on_splitter_splitterMoved();
}


void MainWindow::on_splitter_splitterMoved(int , int )
{
    this->update();
    QList<int> sizes = ui->splitter->sizes();
    const int maxLeftWidth = ui->leftFrame->maximumWidth();
    int totalWidth = sizes[0] + sizes[1];

    if( sizes[0] > maxLeftWidth)
    {
        sizes[0] = maxLeftWidth;
        sizes[1] = totalWidth - maxLeftWidth;
        ui->splitter->setSizes(sizes);
    }
}

MainWindow::SavedState MainWindow::saveCurrentState()
{
    
    
    
    
    
    
    

    
    
    
    
    
}

void MainWindow::onPushUndo()
{
    

    
    
    
    
    
    

    
}

void MainWindow::onUndoInvoked()
{
    

    
    
    
    
    

    

    
    
}

void MainWindow::onRedoInvoked()
{
    

    
    
    
    
    

    

    
    
}

void MainWindow::loadSavedStateFromJson(SavedState saved_state)
{
    
    
    
    
    
    
    
    

    

    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}

void MainWindow::onConnectionUpdate(bool connected)
{
    if(connected)
    {
        ui->toolButtonConnect->setStyleSheet("background-color: rgb(50, 150, 0); color:white");
        ui->toolButtonConnect->setText("Disconnect");
    }
    else{
        ui->toolButtonConnect->setStyleSheet(
            "QToolButton {color:white; }"
            "QToolButton:hover{ background-color: rgb(110, 110, 110); }"
            "QToolButton:pressed{ background-color: rgb(50, 150, 0) }"
            "QToolButton:disabled{color:gray; background-color: rgb(50, 50, 50) }");
        ui->toolButtonConnect->setText("Connect");
    }
}




void MainWindow::onAddToModelRegistry(const NodeModel &model)
{
    
}

void MainWindow::onDestroySubTree(const QString &ID)
{
}

void MainWindow::onModelRemoveRequested(QString ID)
{
    
}



void MainWindow::on_toolButtonReorder_pressed()
{
    
}

void MainWindow::on_toolButtonCenterView_pressed()
{
    
}

void MainWindow::clearUndoStacks()
{
    _undo_stack.clear();
    _redo_stack.clear();
    onSceneChanged();
    onPushUndo();
}

void MainWindow::onCreateAbsBehaviorTree(const AbsBehaviorTree &tree, const QString &bt_name)
{
    auto container = getTabByName(bt_name);
    if( !container )
    {
        container = createTab(bt_name);
    }
    const QSignalBlocker blocker( container );
    container->loadSceneFromTree( tree );
    container->nodeReorder();

    for(const auto& node: tree.nodes())
    {
        if( node.model.type == NodeType::SUBTREE && getTabByName(node.model.registration_ID) == nullptr)
        {
            createTab(node.model.registration_ID);
        }
    }

    
    clearUndoStacks();
}

void MainWindow::on_actionClear_triggered()
{
    onActionClearTriggered(true);
    clearTreeModels();
    clearUndoStacks();
}

void MainWindow::onTreeNodeEdited(QString prev_ID, QString new_ID)
{
}


void MainWindow::onActionClearTriggered(bool create_new)
{



}


void MainWindow::updateCurrentMode()
{



}




void MainWindow::refreshExpandedSubtrees()
{

}

void MainWindow::on_toolButtonLayout_clicked()
{

}

void MainWindow::on_actionEditor_mode_triggered()
{
    _current_mode = GraphicMode::EDITOR;
    updateCurrentMode();






}

void MainWindow::on_actionMonitor_mode_triggered()
{

}

void MainWindow::on_actionReplay_mode_triggered()
{

}

void MainWindow::on_tabWidget_currentChanged(int index)
{

}

bool MainWindow::SavedState::operator ==(const MainWindow::SavedState &other) const
{
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return true;
}

void MainWindow::onChangeNodesStatus(const QString& bt_name,
                                     const std::vector<std::pair<int, NodeStatus> > &node_status)
{
    

    
    
    
    
    

    
    
    
    

    
    
    
    
    
    
    
    
}

void MainWindow::onTabCustomContextMenuRequested(const QPoint &pos)
{
    

    
    

    
    
    
    

    

    
    
    
    

    
    
}

void MainWindow::onTabRenameRequested(int tab_index, QString new_name)
{
    

    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    

    
    
}


void MainWindow::onTabSetMainTree(int tab_index)
{
    
    
    
    
    
    
    
    
    
    
    
}


void MainWindow::clearTreeModels()
{
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
}

const NodeModels &MainWindow::registeredModels() const
{
    return _treenode_models;
}

void MainWindow::on_actionAbout_triggered()
{
    auto ui = new Ui_Dialog;
    QDialog* dialog = new QDialog(this);
    ui->setupUi(dialog);

    auto svg_widget = new QSvgWidget( tr(":/icons/svg/logo_splashscreen.svg") );
    ui->frame->layout()->addWidget(svg_widget);
    dialog->setWindowFlags( Qt::SplashScreen );
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    dialog->show();
}

void MainWindow::on_actionReportIssue_triggered()
{
    
}
