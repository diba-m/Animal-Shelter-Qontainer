#ifndef UI_UNTITLED_H
#define UI_UNTITLED_H

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

class Ui_Form {
public:
    QLabel *idLabel;
    QLineEdit *idEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *ageLabel;
    QSpinBox *ageSpin;
    QLabel *breedLabel;
    QLineEdit *breedEdit;
    QLabel *adoptedLabel;
    QComboBox *adoptedCombo;
    QLabel *typeLabel;
    QComboBox *typeCombo;
    QLabel *genderLabel;
    QComboBox *genderCombo;
    QLabel *vaxLabel;
    QComboBox *vaxCombo;
    QLabel *speciesLabel;
    QLineEdit *speciesEdit;
    QPushButton *submit;
    QPushButton *cancel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(290, 350);
        Form->setMaximumSize(QSize(290, 350));

        idLabel = new QLabel(Form);
        idEdit = new QLineEdit(Form);
        nameLabel = new QLabel(Form);
        nameEdit = new QLineEdit(Form);
        breedLabel = new QLabel(Form);
        breedEdit = new QLineEdit(Form);
        ageLabel = new QLabel(Form);
        ageSpin = new QSpinBox(Form);
        adoptedLabel = new QLabel(Form);
        adoptedCombo = new QComboBox(Form);
        typeLabel = new QLabel(Form);
        typeCombo = new QComboBox(Form);
        genderLabel = new QLabel(Form);
        genderCombo = new QComboBox(Form);
        vaxLabel = new QLabel(Form);
        vaxCombo = new QComboBox(Form);
        speciesLabel = new QLabel(Form);
        speciesEdit = new QLineEdit(Form);
        submit = new QPushButton(Form);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setText("Submit");
        cancel = new QPushButton(Form);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setText("Cancel");

        QHBoxLayout *HLayoutId = new QHBoxLayout;
        HLayoutId->addWidget(idLabel);
        HLayoutId->addWidget(idEdit);
        QHBoxLayout *HLayoutName = new QHBoxLayout;
        HLayoutName->addWidget(nameLabel);
        HLayoutName->addWidget(nameEdit);
        QHBoxLayout *HLayoutBreed = new QHBoxLayout;
        HLayoutBreed->addWidget(breedLabel);
        HLayoutBreed->addWidget(breedEdit);
        QHBoxLayout *HLayoutAge = new QHBoxLayout;
        HLayoutAge->addWidget(ageLabel);
        HLayoutAge->addWidget(ageSpin);
        QHBoxLayout *HLayoutAdopted = new QHBoxLayout;
        HLayoutAdopted->addWidget(adoptedLabel);
        HLayoutAdopted->addWidget(adoptedCombo);
        QHBoxLayout *HLayoutType = new QHBoxLayout;
        HLayoutType->addWidget(typeLabel);
        HLayoutType->addWidget(typeCombo);
        QHBoxLayout *HLayoutGender = new QHBoxLayout;
        HLayoutGender->addWidget(genderLabel);
        HLayoutGender->addWidget(genderCombo);
        QHBoxLayout *HLayoutVax = new QHBoxLayout;
        HLayoutVax->addWidget(vaxLabel);
        HLayoutVax->addWidget(vaxCombo);
        QHBoxLayout *HLayoutSpecies = new QHBoxLayout;
        HLayoutSpecies->addWidget(speciesLabel);
        HLayoutSpecies->addWidget(speciesEdit);
        QHBoxLayout *HLayoutButtons = new QHBoxLayout;
        HLayoutButtons->addWidget(submit);
        HLayoutButtons->addWidget(cancel);

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
        layout->addLayout(HLayoutButtons);

        Form->setLayout(layout);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Add New Animal", nullptr));
        idLabel->setText(QApplication::translate("Form", "ID:", nullptr));
        nameLabel->setText(QApplication::translate("Form", "Name:", nullptr));
        breedLabel->setText(QApplication::translate("Form", "Breed:", nullptr));
        ageLabel->setText(QApplication::translate("Form", "Age:", nullptr));
        adoptedLabel->setText(QApplication::translate("Form", "Adoption Status:", nullptr));
        typeLabel->setText(QApplication::translate("Form", "Type:", nullptr));
        genderLabel->setText(QApplication::translate("Form", "Gender:", nullptr));
        vaxLabel->setText(QApplication::translate("Form", "Vaccination Status:", nullptr));
        speciesLabel->setText(QApplication::translate("Form", "Bird Species:", nullptr));
        idEdit->setFixedWidth(200);
        nameEdit->setFixedWidth(200);
        breedEdit->setFixedWidth(200);
        ageSpin->setValue(0);
        ageSpin->setFixedWidth(165);
        adoptedCombo->addItem("");
        adoptedCombo->addItem("In Foster Care");
        adoptedCombo->addItem("Adopted");
        adoptedCombo->addItem("Not Adopted");
        adoptedCombo->setFixedWidth(165);
        typeCombo->addItem("");
        typeCombo->addItem("Cat");
        typeCombo->addItem("Dog");
        typeCombo->addItem("Bird");
        typeCombo->setFixedWidth(165);
        genderCombo->addItem("Female");
        genderCombo->addItem("Male");
        genderCombo->setFixedWidth(165);
        vaxCombo->setFixedWidth(165);
        speciesEdit->setFixedWidth(200);
        speciesLabel->setVisible(false);
        speciesEdit->setVisible(false);
    } // retranslateUi
};

namespace UiForm {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

class Form : public QWidget {
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr, DeepPtr<Animal> animal = nullptr);
    ~Form() override;
    DeepPtr<Animal> getAnimal();

private slots:
    void on_typeCombo_currentTextChanged();
    void onCancel();
    void onSubmit();

signals:
    void newDataEntered();
    void dataEdit();

private:
    UiForm::Form *ui;

    bool editMode;
    DeepPtr<Animal> _animal;
};

#endif // UI_UNTITLED_H
