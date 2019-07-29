#ifndef BIRD_H
#define BIRD_H

#include "animal.h"

class Bird : public Animal {

public:
    Bird(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender, std::string APV, std::string species);
    std::string type() const override;
    std::string vaccines() const override;
    std::string speak() const override;
    double costOfcare() const override;
    std::string APV() const;
    std::string species() const;
    std::string fly() const;
private:
    std::string _APV; //Avian Polyoma Virus
    std::string _species;
};

#endif
