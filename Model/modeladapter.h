#ifndef MODELADAPTER_H
#define MODELADAPTER_H

#include "jsonparser.h"
#include <QAbstractTableModel>

class ModelAdapter : public QAbstractTableModel {
    Q_OBJECT

public:
    ModelAdapter(QObject *parent = nullptr);
    void readFromFile(QFile &file);
    QJsonDocument saveToFile();
    void deleteByIndex(const std::vector<unsigned> &index);
    void deleteById(const std::vector<unsigned> &ids);
    void addNewItem(DeepPtr<Animal> animal);
    void editItem(DeepPtr<Animal> animal, unsigned index);
    DeepPtr<Animal> getByIndex(unsigned index);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    Container<DeepPtr<Animal>> animals;
};

#endif // MODELADAPTER_H
