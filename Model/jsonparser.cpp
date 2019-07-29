#include "jsonparser.h"

Container<DeepPtr<Animal>> JsonParser::fromFile(QFile &file) {
    Container<DeepPtr<Animal>> buffer;

    QString val = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject jObject = doc.object();

    QJsonArray jsonArray = jObject["Cat"].toArray();

    foreach (const QJsonValue &value, jsonArray) {
        QJsonObject obj = value.toObject();
        buffer.push_back(new Cat(obj["id"].toInt(), obj["name"].toString().toStdString(), obj["age"].toInt(), obj["breed"].toString().toStdString(), obj["adopted"].toString().toStdString(), obj["gender"].toString().toStdString(), obj["FVRCP"].toString().toStdString()));
    }

    jsonArray = jObject["Dog"].toArray();

    foreach (const QJsonValue &value, jsonArray) {
        QJsonObject obj = value.toObject();
        buffer.push_back(new Dog(obj["id"].toInt(), obj["name"].toString().toStdString(), obj["age"].toInt(), obj["breed"].toString().toStdString(), obj["adopted"].toString().toStdString(), obj["gender"].toString().toStdString(), obj["DHLPP"].toString().toStdString()));
    }

    jsonArray = jObject["Bird"].toArray();

    foreach (const QJsonValue &value, jsonArray) {
        QJsonObject obj = value.toObject();
        buffer.push_back(new Bird(obj["id"].toInt(), obj["name"].toString().toStdString(), obj["age"].toInt(), obj["breed"].toString().toStdString(), obj["adopted"].toString().toStdString(), obj["gender"].toString().toStdString(), obj["APV"].toString().toStdString(), obj["species"].toString().toStdString()));
    }

    return buffer;
}

QJsonDocument JsonParser::saveFile(const Container<DeepPtr<Animal>> &animals) {
    QJsonArray cats, dogs, Birds;

    for(auto it=animals.begin();it!=animals.end();it++){
        QJsonObject tmp;
        tmp["adopted"] = QString::fromStdString((*it)->Adopted());
        tmp["age"] = (*it)->Age();
        tmp["breed"] = QString::fromStdString((*it)->Breed());
        tmp["id"] = (*it)->Id();
        tmp["name"] = QString::fromStdString((*it)->Name());
        tmp["gender"] = QString::fromStdString((*it)->Gender());

        if(dynamic_cast<Dog*>(it->_object)) {
            Dog* stat=static_cast<Dog*>((*it)._object);
            tmp["DHLPP"] = QString::fromStdString(stat->DHLPP());
            dogs.push_back(tmp);
        }
        else if (dynamic_cast<Cat*>(it->_object)) {
            Cat* stat=static_cast<Cat*>((*it)._object);
            tmp["FVRCP"] = QString::fromStdString(stat->FVRCP());
            cats.push_back(tmp);
        }
        else {
            Bird* stat=static_cast<Bird*>((*it)._object);
            tmp["APV"] = QString::fromStdString(stat->APV());
            tmp["species"] = QString::fromStdString(stat->species());
            Birds.push_back(tmp);
        }
    }

    QJsonObject main;
    main.insert("Cat", cats);
    main.insert("Dog", dogs);
    main.insert("Bird", Birds);

    return QJsonDocument (main);
}
