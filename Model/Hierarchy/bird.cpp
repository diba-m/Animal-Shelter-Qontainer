#include "bird.h"

Bird::Bird(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender, std::string APV, std::string species)
    : Animal(id, std::move(name), age, std::move(breed), std::move(adopted), std::move(gender)), _APV(APV), _species(species) {

}

std::string Bird::type() const {
    return {"Bird"};
}

std::string Bird::vaccines() const {
    return {"APV"};
}

std::string Bird::speak() const{
    return {"Sing"};
}

double Bird::costOfcare() const{
    if(this->Age()<2) {
        return 15 + _baseCost;
    }
    else if (this->Age()>4) {
        return 25 + _baseCost;
    }
    else {
        return 10 + _baseCost;
    }
}

std::string Bird::APV() const {
    return this->_APV;
}

std::string Bird::species() const {
    return this->_species;
}

std::string Bird::fly() const {
    return {"Bird can fly"};
}
