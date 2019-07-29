#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include "container.h"
#include "deepptr.h"
#include "Hierarchy/cat.h"
#include "Hierarchy/dog.h"
#include "Hierarchy/bird.h"

class JsonParser {

public:
    static Container<DeepPtr<Animal>> fromFile(QFile &file);
    static QJsonDocument saveFile(const Container<DeepPtr<Animal>> &animals);
};

#endif
