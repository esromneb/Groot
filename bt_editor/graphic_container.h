#ifndef GRAPHIC_CONTAINER_H
#define GRAPHIC_CONTAINER_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>

#include "bt_editor_base.h"

// #include <nodes/Node>
// #include <nodes/NodeData>
// #include <nodes/FlowScene>
// #include <nodes/DataModelRegistry>
// #include <nodes/FlowView>

class GraphicContainer : public QObject
{
    Q_OBJECT
public:
    explicit GraphicContainer(std::shared_ptr<void> registry,
                              QWidget *parent = nullptr);

    // EditorFlowScene* scene() { return nullptr; }
    // QtNodes::FlowView*  view() { return nullptr; }

    // const EditorFlowScene* scene()  const{ return nullptr; }
    // const QtNodes::FlowView* view() const { return nullptr; }

    void lockEditing(bool locked);

    // void lockSubtreeEditing(QtNodes::Node& node, bool locked, bool change_style);

    void nodeReorder();

    void zoomHomeView();

    bool containsValidTree() const;

    void clearScene();

    AbsBehaviorTree loadedTree() const;

    void loadSceneFromTree(const AbsBehaviorTree &tree);

    // void appendTreeToNode(QtNodes::Node& node, AbsBehaviorTree &subtree);

    void loadFromJson(const QByteArray& data);

    // QtNodes::Node* substituteNode(QtNodes::Node* old_node, const QString& new_node_ID);




public slots:

    // void onNodeDoubleClicked(QtNodes::Node& root_node);

    void onPortValueDoubleClicked(QLineEdit* edit_value);


signals:

    void addNewModel( const NodeModel &new_model );

    void undoableChange();


    void requestSubTreeCreate(AbsBehaviorTree tree, QString name);

private:
    // EditorFlowScene* _scene;
    // QtNodes::FlowView*  _view;
    // void*  _view;


   bool _signal_was_blocked;

};

#endif // GRAPHIC_CONTAINER_H
