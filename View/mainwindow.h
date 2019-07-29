#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QWidgetAction>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QResizeEvent>
#include "Model/modeladapter.h"
#include "ui_mainwindow.h"
#include <QSortFilterProxyModel>
#include "insertwidget.h"
#include "detailswidget.h"
#include <QMediaPlayer>
#include "Model/sortfilterproxymodel.h"

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void on_actionOpen_file_triggered();
    void on_actionSave_file_triggered();
    void on_actionDelete_triggered();
    void on_actionAdd_triggered();
    void on_actionEdit_triggered();
    void on_actionReset_triggered();
    void on_actionSearch_triggered();
    void on_actionView_details_triggered();
    void on_playSound_triggered();
    void searchChanged();
    void onNewDataEntered();
    void onDataEdit();

private:
    ModelAdapter model;
    Ui::MainWindow *ui;
    QLineEdit *edit;
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *breedEdit;
    QComboBox *adoptedCombo;
    QComboBox *typeCombo;
    QComboBox *genderCombo;
    QComboBox *vaxCombo;
    QLineEdit *speciesEdit;
    QSortFilterProxyModel *proxyModel1_id;
    QSortFilterProxyModel *proxyModel2_name;
    SortFilterProxyModel *proxyModel3_age;
    QSortFilterProxyModel *proxyModel4_breed;
    SortFilterProxyModel *proxyModel5_adopted;
    SortFilterProxyModel *proxyModel6_type;
    SortFilterProxyModel *proxyModel7_gender;
    SortFilterProxyModel *proxyModel8_vax;
    QSortFilterProxyModel *proxyModel9_species;
    Form *form;
    Form1 *form1;
};

#endif
