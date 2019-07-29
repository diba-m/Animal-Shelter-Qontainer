#include "dog.h"

Dog::Dog(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender, std::string DHLPP)
    : Animal(id, std::move(name), age, std::move(breed), std::move(adopted), std::move(gender)), _DHLPP(DHLPP) {

}

std::string Dog::type() const {
    return {"Dog"};
}

std::string Dog::vaccines() const {
    return {"DHLPP"};
}

std::string Dog::speak() const {
    return {"Woof"};
}

double Dog::costOfcare() const{
    if(this->Age()<2) {
        return 30 + _baseCost;
    }
    else if (this->Age()>10) {
        return 45 + _baseCost;
    }
    else {
        return 15 + _baseCost;
    }
}

std::string Dog::DHLPP() const {
    return this->_DHLPP;
}

std::string Dog::bringStick() const {
    return {"Dog can bring a stick"};
}
