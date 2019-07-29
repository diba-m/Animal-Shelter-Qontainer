#include "detailswidget.h"

Form1::Form1(QWidget *parent, DeepPtr<Animal> animal) : QWidget(parent), ui(new UiForm1::Form1) {
    ui->setupUi(this);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(onClose()));
    this->_animal = animal;

    if (animal.isValid()) {
        ui->showIdLabel->setText(QString::number(animal->Id()));
        ui->showNameLabel->setText(QString::fromStdString(animal->Name()));
        ui->showAgeLabel->setText(QString::number(animal->Age()));
        ui->showBreedLabel->setText(QString::fromStdString(animal->Breed()));
        ui->showAdoptedLabel->setText(QString::fromStdString(animal->Adopted()));
        ui->showTypeLabel->setText(QString::fromStdString(animal->type()));
        ui->showGenderLabel->setText(QString::fromStdString(animal->Gender()));
        ui->showCostLabel->setText(QString::number(animal->costOfcare()) + " €");
        if(dynamic_cast<Dog*>(animal._object)){
            Dog* stat=static_cast<Dog*>(animal._object);
            ui->showVaxLabel->clear();
            ui->showVaxLabel->setText(QString::fromStdString(stat->DHLPP()));
        }
        if(dynamic_cast<Cat*>(animal._object)){
            Cat* stat=static_cast<Cat*>(animal._object);
            ui->showVaxLabel->clear();
            ui->showVaxLabel->setText(QString::fromStdString(stat->FVRCP()));
        }
        else if(dynamic_cast<Bird*>(animal._object)){
            Bird* stat=static_cast<Bird*>(animal._object);
            ui->showVaxLabel->clear();
            ui->showVaxLabel->setText(QString::fromStdString(stat->APV()));
            ui->speciesLabel->setVisible(true);
            ui->showSpeciesLabel->setVisible(true);
            ui->showSpeciesLabel->setText(QString::fromStdString(stat->species()));
        }
    }
}

void Form1::onClose() {
    close();
}

Form1::~Form1() {
    delete ui;
}

DeepPtr<Animal> Form1::getAnimal() {
    return _animal;
}
