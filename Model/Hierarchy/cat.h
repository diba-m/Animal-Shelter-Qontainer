#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal {

public:
    Cat(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender, std::string FVRCP);
    std::string type() const override;
    std::string vaccines() const override;
    std::string speak() const override;
    double costOfcare() const override;
    std::string climbTree() const;
    std::string FVRCP() const;
private:
    std::string _FVRCP; //Feline Viral Rhinotracheitis, Calicivirus, and Panleukopenia
};


#endif
