#include "animal.h"

Animal::Animal(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender)
    : _id(id), _name(std::move(name)), _age(age), _breed(std::move(breed)), _adopted(std::move(adopted)), _gender(std::move(gender)) {

}

Animal::~Animal() {

}

int Animal::Id() const {
    return this->_id;
}

std::string Animal::Name() const {
    return this->_name;
}

int Animal::Age() const {
    return this->_age;
}

std::string Animal::Breed() const {
    return this->_breed;
}

std::string Animal::Adopted() const {
    return this->_adopted;
}

std::string Animal::Gender() const {
    return this->_gender;
}

double Animal::_baseCost = 50;

