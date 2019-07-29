#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QObject>
#include <QTableView>

class TableView : public QTableView {
    Q_OBJECT

public:
    TableView(QWidget* = nullptr);
    void mousePressEvent(QMouseEvent*) override;
    std::vector<unsigned> CurrentIndex();
    void clearIndexes();

private:
    std::vector<unsigned> current_indexes;


    // QWidget interface
protected:
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // TABLEVIEW_H
