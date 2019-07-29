#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QMainWindow>
#include "tableview.h"
#include <QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {

public:
    QAction *playSound;
    QAction *actionAdd;
    QAction *actionDelete;
    QAction *actionEdit;
    QAction *actionOpen_file;
    QAction *actionSave_file;
    QAction *actionReset;
    QAction *actionView_details;
    QAction *actionSearch;
    QWidget *centralWidget;
    QWidget *searchWidget;
    QDockWidget *searchBox;
    TableView *tableView;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(920, 600);

        playSound = new QAction(MainWindow);
        playSound->setObjectName(QString::fromUtf8("playSound"));
        QIcon icon0;
        icon0.addFile(QString::fromUtf8(":/res/speak.png"), QSize(), QIcon::Normal, QIcon::Off);
        playSound->setIcon(icon0);

        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);

        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon1);

        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon2);

        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon3);

        actionSave_file = new QAction(MainWindow);
        actionSave_file->setObjectName(QString::fromUtf8("actionSave_file"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_file->setIcon(icon4);

        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon5);

        actionView_details = new QAction(MainWindow);
        actionView_details->setObjectName(QString::fromUtf8("actionView_details"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/details.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_details->setIcon(icon6);

        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon7);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new TableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 1103, 799));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1103, 24));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        searchBox = new QDockWidget("Search", MainWindow);
        searchBox->setObjectName(QString::fromUtf8("SearchBoxWidget"));
        searchWidget = new QWidget(MainWindow);
        searchWidget->show();
        searchBox->setWidget(searchWidget);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, searchBox);
        searchBox->setVisible(false);

        toolBar->addAction(actionOpen_file);
        toolBar->addAction(actionSave_file);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionView_details);
        toolBar->addAction(actionEdit);
        toolBar->addSeparator();
        toolBar->addAction(playSound);
        toolBar->addSeparator();
        toolBar->addAction(actionSearch);
        toolBar->addAction(actionReset);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        playSound->setText(QApplication::translate("MainWindow", "Play sound", nullptr));
#ifndef QT_NO_TOOLTIP
        playSound->setToolTip(QApplication::translate("MainWindow", "Play sound", nullptr));
#endif // QT_NO_TOOLTIP
        actionAdd->setText(QApplication::translate("MainWindow", "Add item", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindow", "Add item", nullptr));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("MainWindow", "Delete", nullptr));
#endif // QT_NO_TOOLTIP
        actionSearch->setText(QApplication::translate("MainWindow", "Search", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSearch->setToolTip(QApplication::translate("MainWindow", "Search", nullptr));
#endif // QT_NO_TOOLTIP
        actionView_details->setText(QApplication::translate("MainWindow", "View details", nullptr));
#ifndef QT_NO_TOOLTIP
        actionView_details->setToolTip(QApplication::translate("MainWindow", "View details", nullptr));
#endif // QT_NO_TOOLTIP
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", nullptr));        
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MainWindow", "Edit", nullptr));
#endif // QT_NO_TOOLTIP
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen_file->setToolTip(QApplication::translate("MainWindow", "Open file", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave_file->setText(QApplication::translate("MainWindow", "Save file", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_file->setToolTip(QApplication::translate("MainWindow", "Save file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        actionReset->setToolTip(QApplication::translate("MainWindow", "Reset search fields", nullptr));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

#endif
