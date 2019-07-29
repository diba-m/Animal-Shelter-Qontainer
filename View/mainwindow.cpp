#include "mainwindow.h"
#include "Model/Hierarchy/cat.h"
#include "Model/Hierarchy/dog.h"
#include "Model/Hierarchy/bird.h"
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    proxyModel1_id = new QSortFilterProxyModel(this);
    proxyModel2_name = new QSortFilterProxyModel(this);
    proxyModel3_age = new SortFilterProxyModel(this);
    proxyModel4_breed = new QSortFilterProxyModel(this);
    proxyModel5_adopted = new SortFilterProxyModel(this);
    proxyModel6_type = new SortFilterProxyModel(this);
    proxyModel7_gender = new SortFilterProxyModel(this);
    proxyModel8_vax = new SortFilterProxyModel(this);
    proxyModel9_species = new QSortFilterProxyModel(this);

    proxyModel1_id->setSourceModel(&model);
    proxyModel2_name->setSourceModel(proxyModel1_id);
    proxyModel3_age->setSourceModel(proxyModel2_name);
    proxyModel4_breed->setSourceModel(proxyModel3_age);
    proxyModel5_adopted->setSourceModel(proxyModel4_breed);
    proxyModel6_type->setSourceModel(proxyModel5_adopted);
    proxyModel7_gender->setSourceModel(proxyModel6_type);
    proxyModel8_vax->setSourceModel(proxyModel7_gender);
    proxyModel9_species->setSourceModel(proxyModel8_vax);
    ui->tableView->setModel(proxyModel9_species);

    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(2,40);
    ui->tableView->setColumnWidth(3,150);
    ui->tableView->setColumnWidth(5,50);
    ui->tableView->setColumnWidth(6,60);
    ui->tableView->setColumnWidth(7,170);
    ui->tableView->setColumnWidth(8,80);

    QLabel *idLabel = new QLabel(ui->searchWidget);
    idLabel->setText(" ID:");
    idEdit = new QLineEdit(ui->searchWidget);
    QLabel *nameLabel = new QLabel(ui->searchWidget);
    nameLabel->setText(" Name:");
    nameEdit = new QLineEdit(ui->searchWidget);
    QLabel *ageLabel = new QLabel(ui->searchWidget);
    ageLabel->setText(" Age:");
    ageEdit = new QLineEdit(ui->searchWidget);
    QLabel *breedLabel = new QLabel(ui->searchWidget);
    breedLabel->setText(" Breed:");
    breedEdit = new QLineEdit(ui->searchWidget);
    QLabel *adoptedLabel = new QLabel(ui->searchWidget);
    adoptedLabel->setText(" Adoption status");
    adoptedCombo = new QComboBox(ui->searchWidget);
    adoptedCombo->addItem("");
    adoptedCombo->addItem("In Foster Care");
    adoptedCombo->addItem("Adopted");
    adoptedCombo->addItem("Not Adopted");
    QLabel *typeLabel = new QLabel(ui->searchWidget);
    typeLabel->setText(" Type:");
    typeCombo = new QComboBox(ui->searchWidget);
    typeCombo->addItem("");
    typeCombo->addItem("Cat");
    typeCombo->addItem("Dog");
    typeCombo->addItem("Bird");
    QLabel *genderLabel = new QLabel(ui->searchWidget);
    genderLabel->setText(" Gender:");
    genderCombo = new QComboBox(ui->searchWidget);
    genderCombo->addItem("");
    genderCombo->addItem("Female");
    genderCombo->addItem("Male");
    QLabel *vaxLabel =  new QLabel(ui->searchWidget);
    vaxLabel->setText(" Vaccination status:");
    vaxCombo = new QComboBox(ui->searchWidget);
    vaxCombo->addItem("");
    vaxCombo->addItem("FVRCP vaccinated");
    vaxCombo->addItem("Not FVRCP vaccinated");
    vaxCombo->addItem("FVRCP vaccination scheduled");
    vaxCombo->addItem("DHLPP vaccinated");
    vaxCombo->addItem("Not DHLPP vaccinated");
    vaxCombo->addItem("DHLPP vaccination scheduled");
    vaxCombo->addItem("APV vaccinated");
    vaxCombo->addItem("Not APV vaccinated");
    vaxCombo->addItem("APV vaccination scheduled");
    QLabel *speciesLabel = new QLabel(ui->searchWidget);
    speciesLabel->setText(" Bird Species:");
    speciesEdit = new QLineEdit(ui->searchWidget);

    QHBoxLayout *searchBoxLayout = new QHBoxLayout;
    searchBoxLayout->addWidget(idLabel);
    searchBoxLayout->addWidget(idEdit);
    searchBoxLayout->addWidget(nameLabel);
    searchBoxLayout->addWidget(nameEdit);
    searchBoxLayout->addWidget(ageLabel);
    searchBoxLayout->addWidget(ageEdit);
    searchBoxLayout->addWidget(breedLabel);
    searchBoxLayout->addWidget(breedEdit);

    QHBoxLayout *searchBoxLayout2 = new QHBoxLayout;
    searchBoxLayout2->addWidget(adoptedLabel);
    searchBoxLayout2->addWidget(adoptedCombo);
    searchBoxLayout2->addWidget(typeLabel);
    searchBoxLayout2->addWidget(typeCombo);
    searchBoxLayout2->addWidget(genderLabel);
    searchBoxLayout2->addWidget(genderCombo);
    searchBoxLayout2->addWidget(vaxLabel);
    searchBoxLayout2->addWidget(vaxCombo);
    searchBoxLayout2->addWidget(speciesLabel);
    searchBoxLayout2->addWidget(speciesEdit);

    QVBoxLayout *searchBox = new QVBoxLayout;
    searchBox->addLayout(searchBoxLayout);
    searchBox->addLayout(searchBoxLayout2);




    ui->searchWidget->setLayout(searchBox);

    connect(idEdit, SIGNAL(textChanged(const QString&)), this, SLOT(searchChanged()));
    connect(nameEdit, SIGNAL(textChanged(const QString&)), this, SLOT(searchChanged()));
    connect(ageEdit, SIGNAL(textChanged(const QString&)), this, SLOT(searchChanged()));
    connect(breedEdit, SIGNAL(textChanged(const QString&)), this, SLOT(searchChanged()));
    connect(adoptedCombo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(searchChanged()));
    connect(typeCombo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(searchChanged()));
    connect(genderCombo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(searchChanged()));
    connect(vaxCombo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(searchChanged()));
    connect(speciesEdit, SIGNAL(textChanged(const QString&)), this, SLOT(searchChanged()));

    setWindowTitle("Animal Shelter Manager");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event) {
   QMainWindow::resizeEvent(event);
   ui->tableView->setMinimumWidth(width());
   ui->tableView->setMaximumWidth(width());

   ui->tableView->setMinimumHeight(height());
   ui->tableView->setMaximumHeight(height());
}

void MainWindow::searchChanged() {

    proxyModel1_id->setFilterRegExp(QRegExp(idEdit->text(), Qt::CaseInsensitive));
    proxyModel1_id->setFilterKeyColumn(0);
    proxyModel2_name->setFilterRegExp(QRegExp(nameEdit->text(), Qt::CaseInsensitive));
    proxyModel2_name->setFilterKeyColumn(1);
    proxyModel3_age->setFixedString(ageEdit->text());
    proxyModel3_age->setFilterKeyColumn(2);
    proxyModel4_breed->setFilterRegExp(QRegExp(breedEdit->text(), Qt::CaseInsensitive));
    proxyModel4_breed->setFilterKeyColumn(3);
    proxyModel5_adopted->setFixedString(adoptedCombo->currentText());
    proxyModel5_adopted->setFilterKeyColumn(4);
    proxyModel6_type->setFixedString(typeCombo->currentText());
    proxyModel6_type->setFilterKeyColumn(5);
    proxyModel7_gender->setFixedString(genderCombo->currentText());
    proxyModel7_gender->setFilterKeyColumn(6);
    proxyModel8_vax->setFixedString(vaxCombo->currentText());
    proxyModel8_vax->setFilterKeyColumn(7);
    proxyModel9_species->setFilterRegExp(QRegExp(speciesEdit->text(), Qt::CaseInsensitive));
    proxyModel9_species->setFilterKeyColumn(8);
}

void MainWindow::onNewDataEntered() {
    model.addNewItem(form->getAnimal());
}

void MainWindow::onDataEdit() {
    model.editItem(form->getAnimal(), ui->tableView->CurrentIndex()[0]);
}

void MainWindow::on_actionOpen_file_triggered() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open JSON"), "/", tr("JSON Files (*.json)"));

    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    model.readFromFile(file);
    file.close();
}

void MainWindow::on_actionSave_file_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save JSON"), "/", tr("JSON Files (*.json)"));
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(model.saveToFile().toJson());
    jsonFile.close();
}

void MainWindow::on_actionDelete_triggered() {
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to delete animal?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    if(ret == QMessageBox::Ok) {
        std::vector<unsigned> indexes = ui->tableView->CurrentIndex();

        if (indexes.empty()) {
            return;
        }
        auto end = indexes.end();
        for (auto it = indexes.begin(); it != end; ++it) {
            end = std::remove(it + 1, end, *it);
        }
        indexes.erase(end, indexes.end());

        std::vector<unsigned> ids;
        for (auto &i : indexes) {
            QModelIndex index = ui->tableView->model()->index(i, 0);
            ids.push_back(index.data().toInt());
        }
        model.deleteById(ids);
        ui->tableView->clearIndexes();
    }

    else return;
}

void MainWindow::on_actionAdd_triggered() {
    form = new Form();
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
    QObject::connect(form, SIGNAL(newDataEntered()), this, SLOT(onNewDataEntered()));
}
void MainWindow::on_actionReset_triggered() {
    idEdit->setText("");
    nameEdit->setText("");
    ageEdit->setText("");
    breedEdit->setText("");
    adoptedCombo->setCurrentIndex(0);
    typeCombo->setCurrentIndex(0);
    genderCombo->setCurrentIndex(0);
    vaxCombo->setCurrentIndex(0);
    speciesEdit->setText("");
}
void MainWindow::on_actionSearch_triggered() {
    if(ui->searchBox->isVisible()) {
        ui->searchBox->setVisible(false);
    }
    else {
        ui->searchBox->setVisible(true);
    }
}

void MainWindow::on_actionEdit_triggered() {
    if (ui->tableView->CurrentIndex().empty()) {
        return;
    }
    form = new Form(nullptr, model.getByIndex(ui->tableView->CurrentIndex()[0]));
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
    QObject::connect(form, SIGNAL(dataEdit()), this, SLOT(onDataEdit()));
}

void MainWindow::on_actionView_details_triggered() {
    if (ui->tableView->CurrentIndex().empty()) {
        return;
    }
    form1 = new Form1(nullptr, model.getByIndex(ui->tableView->CurrentIndex()[0]));
    form1->setAttribute(Qt::WA_DeleteOnClose);
    form1->show();
    //QObject::connect(form1, SIGNAL(dataEdit()), this, SLOT(onDataEdit()));
}



void MainWindow::on_playSound_triggered() {
    if (ui->tableView->CurrentIndex().empty()) {
        return;
    }

    QString type = ui->tableView->model()->index(ui->tableView->CurrentIndex()[0], 5).data().toString();
    QMediaPlayer *player = new QMediaPlayer();

    if (type == "Cat") {
        player->setMedia(QUrl("qrc:/res/cat.mp3"));
    }
    else if (type == "Dog") {
        player->setMedia(QUrl("qrc:/res/dog.mp3"));
    }
    else {
        player->setMedia(QUrl("qrc:/res/Bird.mp3"));
    }
    player->setVolume(100);
    player->play();
}
