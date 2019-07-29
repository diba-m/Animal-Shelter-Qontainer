#ifndef DETAILSWIDGET_H
#define DETAILSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "Model/Hierarchy/cat.h"
#include "Model/Hierarchy/bird.h"
#include "Model/Hierarchy/dog.h"
#include "Model/deepptr.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE

class Ui_Form1 {
public:
    QLabel *idLabel;
    QLabel *showIdLabel;
    QLabel *nameLabel;
    QLabel *showNameLabel;
    QLabel *ageLabel;
    QLabel *showAgeLabel;
    QLabel *breedLabel;
    QLabel *showBreedLabel;
    QLabel *adoptedLabel;
    QLabel *showAdoptedLabel;
    QLabel *typeLabel;
    QLabel *showTypeLabel;
    QLabel *genderLabel;
    QLabel *showGenderLabel;
    QLabel *vaxLabel;
    QLabel *showVaxLabel;
    QLabel *speciesLabel;
    QLabel *showSpeciesLabel;
    QLabel *costLabel;
    QLabel *showCostLabel;
    QPushButton *close;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName(QString::fromUtf8("Form1"));
        Form1->resize(290, 350);
        Form1->setMaximumSize(QSize(290, 350));

        idLabel = new QLabel(Form1);
        showIdLabel = new QLabel(Form1);
        nameLabel = new QLabel(Form1);
        showNameLabel = new QLabel(Form1);
        breedLabel = new QLabel(Form1);
        showBreedLabel = new QLabel(Form1);
        ageLabel = new QLabel(Form1);
        showAgeLabel = new QLabel(Form1);
        adoptedLabel = new QLabel(Form1);
        showAdoptedLabel = new QLabel(Form1);
        typeLabel = new QLabel(Form1);
        showTypeLabel = new QLabel(Form1);
        genderLabel = new QLabel(Form1);
        showGenderLabel = new QLabel(Form1);
        vaxLabel = new QLabel(Form1);
        showVaxLabel = new QLabel(Form1);
        speciesLabel = new QLabel(Form1);
        showSpeciesLabel = new QLabel(Form1);
        costLabel = new QLabel(Form1);
        showCostLabel = new QLabel(Form1);
        close = new QPushButton(Form1);
        close->setObjectName(QString::fromUtf8("close"));
        close->setText("Close");

        QHBoxLayout *HLayoutId = new QHBoxLayout;
        HLayoutId->addWidget(idLabel);
        HLayoutId->addWidget(showIdLabel);
        QHBoxLayout *HLayoutName = new QHBoxLayout;
        HLayoutName->addWidget(nameLabel);
        HLayoutName->addWidget(showNameLabel);
        QHBoxLayout *HLayoutBreed = new QHBoxLayout;
        HLayoutBreed->addWidget(breedLabel);
        HLayoutBreed->addWidget(showBreedLabel);
        QHBoxLayout *HLayoutAge = new QHBoxLayout;
        HLayoutAge->addWidget(ageLabel);
        HLayoutAge->addWidget(showAgeLabel);
        QHBoxLayout *HLayoutAdopted = new QHBoxLayout;
        HLayoutAdopted->addWidget(adoptedLabel);
        HLayoutAdopted->addWidget(showAdoptedLabel);
        QHBoxLayout *HLayoutType = new QHBoxLayout;
        HLayoutType->addWidget(typeLabel);
        HLayoutType->addWidget(showTypeLabel);
        QHBoxLayout *HLayoutGender = new QHBoxLayout;
        HLayoutGender->addWidget(genderLabel);
        HLayoutGender->addWidget(showGenderLabel);
        QHBoxLayout *HLayoutVax = new QHBoxLayout;
        HLayoutVax->addWidget(vaxLabel);
        HLayoutVax->addWidget(showVaxLabel);
        QHBoxLayout *HLayoutSpecies = new QHBoxLayout;
        HLayoutSpecies->addWidget(speciesLabel);
        HLayoutSpecies->addWidget(showSpeciesLabel);
        QHBoxLayout *HLayoutCost = new QHBoxLayout;
        HLayoutCost->addWidget(costLabel);
        HLayoutCost->addWidget(showCostLabel);
        QHBoxLayout *HLayoutButtons = new QHBoxLayout;
        HLayoutButtons->addWidget(close);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addLayout(HLayoutId);
        layout->addLayout(HLayoutName);
        layout->addLayout(HLayoutBreed);
        layout->addLayout(HLayoutAge);
        layout->addLayout(HLayoutAdopted);
        layout->addLayout(HLayoutType);
        layout->addLayout(HLayoutGender);
        layout->addLayout(HLayoutVax);
        layout->addLayout(HLayoutSpecies);
        layout->addLayout(HLayoutCost);
        layout->addLayout(HLayoutButtons);

        Form1->setLayout(layout);

        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QApplication::translate("Form1", "View Details", nullptr));
        idLabel->setText(QApplication::translate("Form1", "ID:", nullptr));
        nameLabel->setText(QApplication::translate("Form1", "Name:", nullptr));
        breedLabel->setText(QApplication::translate("Form1", "Breed:", nullptr));
        ageLabel->setText(QApplication::translate("Form1", "Age:", nullptr));
        adoptedLabel->setText(QApplication::translate("Form1", "Adoption Status:", nullptr));
        typeLabel->setText(QApplication::translate("Form1", "Type:", nullptr));
        genderLabel->setText(QApplication::translate("Form1", "Gender:", nullptr));
        vaxLabel->setText(QApplication::translate("Form1", "Vaccination Status:", nullptr));
        speciesLabel->setText(QApplication::translate("Form1", "Bird Species:", nullptr));
        costLabel->setText(QApplication::translate("Form1", "Monthly Cost for Care:", nullptr));
        costLabel->setFixedWidth(200);
        showCostLabel->setFixedWidth(200);
        idLabel->setFixedWidth(200);
        showIdLabel->setFixedWidth(200);
        nameLabel->setFixedWidth(200);
        showNameLabel->setFixedWidth(200);
        breedLabel->setFixedWidth(200);
        showBreedLabel->setFixedWidth(200);
        ageLabel->setFixedWidth(200);
        showAgeLabel->setFixedWidth(200);
        adoptedLabel->setFixedWidth(200);
        showAdoptedLabel->setFixedWidth(200);
        typeLabel->setFixedWidth(200);
        showTypeLabel->setFixedWidth(200);
        genderLabel->setFixedWidth(200);
        showGenderLabel->setFixedWidth(200);
        vaxLabel->setFixedWidth(200);
        showVaxLabel->setFixedWidth(200);
        speciesLabel->setFixedWidth(200);
        showSpeciesLabel->setFixedWidth(200);
        speciesLabel->setVisible(false);
        showSpeciesLabel->setVisible(false);
    } // retranslateUi

};

namespace UiForm1 {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

class Form1 : public QWidget {
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr, DeepPtr<Animal> animal = nullptr);
    ~Form1() override;
    DeepPtr<Animal> getAnimal();

private slots:
    void onClose();

private:
    UiForm1::Form1 *ui;
    DeepPtr<Animal> _animal;
};

#endif // DETAILSWIDGET_H
