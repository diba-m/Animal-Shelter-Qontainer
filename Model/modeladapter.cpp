#include "modeladapter.h"

ModelAdapter::ModelAdapter(QObject *parent) : QAbstractTableModel(parent) {

}

void ModelAdapter::readFromFile(QFile &file) {
    beginResetModel();
    this->animals = JsonParser::fromFile(file);
    endResetModel();
}

QJsonDocument ModelAdapter::saveToFile() {
    return JsonParser::saveFile(animals);
}

void ModelAdapter::deleteByIndex(const std::vector<unsigned> &index) {
    beginResetModel();

    for (const auto &i : index) {
        animals.erase(i);
    }

    endResetModel();
}

void ModelAdapter::deleteById(const std::vector<unsigned> &ids) {
    beginResetModel();

    for (const auto &id : ids) {
        for (unsigned i = 0; i < animals.size(); ++i) {
            if (animals[i]->Id() == static_cast<int> (id)) {
                animals.erase(i);
                break;
            }
        }
    }

    endResetModel();
}

void ModelAdapter::addNewItem(DeepPtr<Animal> animal) {
    beginResetModel();
    animals.push_back(std::move(animal));
    endResetModel();
}

void ModelAdapter::editItem(DeepPtr<Animal> animal, unsigned index) {
    animals[index] = std::move(animal);
}

DeepPtr<Animal> ModelAdapter::getByIndex(unsigned index) {
    return animals[index];
}

int ModelAdapter::rowCount(const QModelIndex &parent) const {
    return animals.size();
}

int ModelAdapter::columnCount(const QModelIndex &parent) const {
    return 9;
}

QVariant ModelAdapter::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {

        switch (index.column()) {
            case 0:
                return animals[index.row()]->Id();
            case 1:
                return QString::fromStdString(animals[index.row()]->Name());
            case 2:
                return animals[index.row()]->Age();
            case 3:
                return QString::fromStdString(animals[index.row()]->Breed());
            case 4:
                return QString::fromStdString(animals[index.row()]->Adopted());
            case 5:
                return QString::fromStdString(animals[index.row()]->type());
            case 6:
                return QString::fromStdString(animals[index.row()]->Gender());
            case 7:
                if(dynamic_cast<Dog*>(animals[index.row()]._object)){
                    Dog* stat=static_cast<Dog*>(animals[index.row()]._object);
                    return QString::fromStdString(stat->DHLPP());
                }
                if(dynamic_cast<Cat*>(animals[index.row()]._object)){
                    Cat* stat=static_cast<Cat*>(animals[index.row()]._object);
                    return QString::fromStdString(stat->FVRCP());
                }
                else{
                    Bird* stat=static_cast<Bird*>(animals[index.row()]._object);
                    return QString::fromStdString(stat->APV());
                }
            case 8:
                if(dynamic_cast<Bird*>(animals[index.row()]._object)){
                    Bird* stat=static_cast<Bird*>(animals[index.row()]._object);
                    return QString::fromStdString(stat->species());
                }
        }
    }

    return QVariant();
}

Qt::ItemFlags ModelAdapter::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant ModelAdapter::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
             return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
             return tr("Id");
            case 1:
             return tr("Name");
            case 2:
             return tr("Age");
            case 3:
             return tr("Breed");
            case 4:
             return tr("Adoption Status");
            case 5:
             return tr("Type");
            case 6:
             return tr("Gender");
            case 7:
             return tr("Vaccines");
            case 8:
             return tr("Bird Species");
            default:
             return QVariant();
        }
    }
    if (orientation == Qt::Vertical) {
        return section;
    }
    return QVariant();
}
