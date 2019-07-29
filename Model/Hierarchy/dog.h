#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal {

public:
    Dog(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender, std::string DHLPP) ;
    std::string type() const override;
    std::string vaccines() const override;
    std::string speak() const override;
    double costOfcare() const override;
    std::string DHLPP() const;
    std::string bringStick() const;
private:
    std::string _DHLPP; //Canine 5-way Vaccine: Distemper, Hepatitis (Adenovirus), Leptospira, Parainfluenza and Parvovirus
};

#endif
