#include "cat.h"

Cat::Cat(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender, std::string FVRCP)
    : Animal(id, std::move(name), age, std::move(breed), std::move(adopted), std::move(gender)), _FVRCP(FVRCP) {

}

std::string Cat::type() const {
    return {"Cat"};
}

std::string Cat::vaccines() const {
    return {"FVRCP"};
}

std::string Cat::speak() const {
    return {"Meow"};
}

double Cat::costOfcare() const{
    if(this->Age()<2) {
        return 25 + _baseCost;
    }
    else if (this->Age()>8) {
        return 40 + _baseCost;
    }
    else {
        return 10 + _baseCost;
    }
}
std::string Cat::FVRCP() const {
    return this->_FVRCP;
}

std::string Cat::climbTree() const {
    return {"Cat can climb a tree"};
}
