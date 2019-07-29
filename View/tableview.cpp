#include "tableview.h"
#include <QMouseEvent>
#include <QHeaderView>
#include <QDebug>

TableView::TableView(QWidget* parent) : QTableView(parent) {
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

void TableView::mousePressEvent(QMouseEvent* event) {
    current_indexes.clear();

     if (!indexAt(event->pos()).isValid()) {
        clearSelection();
        selectionModel()->clearCurrentIndex();
    }

    QTableView::mousePressEvent(event);
    if (!selectedIndexes().isEmpty()) {
        for (auto i : selectedIndexes()) {
            current_indexes.push_back(i.row());
        }
    }
}

std::vector<unsigned> TableView::CurrentIndex() {
    return this->current_indexes;
}

void TableView::clearIndexes() {
    current_indexes.clear();
}

void TableView::keyReleaseEvent(QKeyEvent *event) {
    current_indexes.clear();

    if (!selectedIndexes().isEmpty()) {
        for (auto i : selectedIndexes()) {
            current_indexes.push_back(i.row());
        }
    }
}



