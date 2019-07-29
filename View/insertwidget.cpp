#include "insertwidget.h"

Form::Form(QWidget *parent, DeepPtr<Animal> animal) : QWidget(parent), ui(new UiForm::Form) {
    ui->setupUi(this);
    connect(ui->typeCombo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(on_typeCombo_currentTextChanged()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(onCancel()));
    connect(ui->submit, SIGNAL(clicked()), this, SLOT(onSubmit()));
    this->_animal = animal;

    if (animal.isValid()) {
        editMode = true;
        ui->idEdit->setText(QString::number(animal->Id()));
        ui->nameEdit->setText(QString::fromStdString(animal->Name()));
        ui->ageSpin->setValue(animal->Age());
        ui->breedEdit->setText(QString::fromStdString(animal->Breed()));
        ui->adoptedCombo->setCurrentText(QString::fromStdString(animal->Adopted()));
        ui->typeCombo->setCurrentText(QString::fromStdString(animal->type()));
        ui->genderCombo->setCurrentText(QString::fromStdString(animal->Gender()));
        if(dynamic_cast<Dog*>(animal._object)){
            Dog* stat=static_cast<Dog*>(animal._object);
            ui->vaxCombo->clear();
            ui->vaxCombo->addItem("DHLPP vaccinated");
            ui->vaxCombo->addItem("Not DHLPP vaccinated");
            ui->vaxCombo->addItem("DHLPP vaccination scheduled");
            ui->vaxCombo->setCurrentText(QString::fromStdString(stat->DHLPP()));
        }
        if(dynamic_cast<Cat*>(animal._object)){
            Cat* stat=static_cast<Cat*>(animal._object);
            ui->vaxCombo->clear();
            ui->vaxCombo->addItem("FVRCP vaccinated");
            ui->vaxCombo->addItem("Not FVRCP vaccinated");
            ui->vaxCombo->addItem("FVRCP vaccination scheduled");
            ui->vaxCombo->setCurrentText(QString::fromStdString(stat->FVRCP()));
        }
        else if(dynamic_cast<Bird*>(animal._object)){
            Bird* stat=static_cast<Bird*>(animal._object);
            ui->vaxCombo->clear();
            ui->vaxCombo->addItem("APV vaccinated");
            ui->vaxCombo->addItem("Not APV vaccinated");
            ui->vaxCombo->addItem("APV vaccination scheduled");
            ui->vaxCombo->setCurrentText(QString::fromStdString(stat->APV()));
            ui->speciesEdit->setText(QString::fromStdString(stat->species()));
        }


    }
    else {
        editMode = false;
    }
}

void Form::on_typeCombo_currentTextChanged(){
    if(ui->typeCombo->currentText() == "Cat"){
        ui->vaxCombo->clear();
        ui->vaxCombo->addItem("FVRCP vaccinated");
        ui->vaxCombo->addItem("Not FVRCP vaccinated");
        ui->vaxCombo->addItem("FVRCP vaccination scheduled");
        if(ui->speciesEdit->isVisible() || ui->speciesLabel->isVisible()){
            ui->speciesEdit->setVisible(false);
            ui->speciesLabel->setVisible(false);
        }
    }
    else if(ui->typeCombo->currentText() == "Dog"){
        ui->vaxCombo->clear();
        ui->vaxCombo->addItem("DHLPP vaccinated");
        ui->vaxCombo->addItem("Not DHLPP vaccinated");
        ui->vaxCombo->addItem("DHLPP vaccination scheduled");
        if(ui->speciesEdit->isVisible() || ui->speciesLabel->isVisible()){
            ui->speciesEdit->setVisible(false);
            ui->speciesLabel->setVisible(false);
        }
    }
    else if(ui->typeCombo->currentText() == "Bird"){
        ui->vaxCombo->clear();
        ui->vaxCombo->addItem("APV vaccinated");
        ui->vaxCombo->addItem("Not APV vaccinated");
        ui->vaxCombo->addItem("APV vaccination scheduled");
        ui->speciesLabel->setVisible(true);
        ui->speciesEdit->setVisible(true);
    }
}

void Form::onCancel() {
    close();
}

void Form::onSubmit() {
    try {
        if (ui->idEdit->text().toInt() < 1000 || ui->idEdit->text().toInt() > 9999 || ui->idEdit->text().isEmpty()) {
            throw std::runtime_error("Invalid ID\n Hint: Enter a four digit ID");
        }
        if (ui->nameEdit->text().isEmpty()) {
            throw std::runtime_error("Empty name field");
        }
        if (ui->breedEdit->text().isEmpty()) {
            throw std::runtime_error("Empty breed field");
        }
        if (ui->ageSpin->value() == 0) {
            throw std::runtime_error("Invalid age");
        }
        if (ui->adoptedCombo->currentText() == "") {
            throw std::runtime_error("Invalid adoption status");
        }
        if (ui->typeCombo->currentText() == "") {
            throw std::runtime_error("Invalid animal type");
        }
        if (ui->genderCombo->currentText() == "") {
            throw std::runtime_error("Invalid gender");
        }
        if (ui->vaxCombo->currentText() == "") {
            throw std::runtime_error("Invalid vaccination status");
        }
        if (ui->speciesEdit->isVisible() && ui->speciesEdit->text().isEmpty()) {
            throw std::runtime_error("Empty bird species field");
        }
    }
    catch(const std::exception &e) {
        QMessageBox::warning(this, "Invalid input", e.what());
        return;
    }

    if (ui->typeCombo->currentText() == "Cat") {
        _animal = new Cat(ui->idEdit->text().toInt(), ui->nameEdit->text().toStdString(), ui->ageSpin->value(), ui->breedEdit->text().toStdString(), ui->adoptedCombo->currentText().toStdString(),ui->genderCombo->currentText().toStdString(), ui->vaxCombo->currentText().toStdString());
    }
    else if (ui->typeCombo->currentText() == "Dog") {
        _animal = new Dog(ui->idEdit->text().toInt(), ui->nameEdit->text().toStdString(), ui->ageSpin->value(), ui->breedEdit->text().toStdString(), ui->adoptedCombo->currentText().toStdString(),ui->genderCombo->currentText().toStdString(), ui->vaxCombo->currentText().toStdString());
    }
    else {
        _animal = new Bird(ui->idEdit->text().toInt(), ui->nameEdit->text().toStdString(), ui->ageSpin->value(), ui->breedEdit->text().toStdString(), ui->adoptedCombo->currentText().toStdString(),ui->genderCombo->currentText().toStdString(), ui->vaxCombo->currentText().toStdString(), ui->speciesEdit->text().toStdString());
    }

    if (editMode) {
        emit dataEdit();
    }
    else {
        emit newDataEntered();
    }

    close();
}

Form::~Form() {
    delete ui;
}

DeepPtr<Animal> Form::getAnimal() {
    return _animal;
}
