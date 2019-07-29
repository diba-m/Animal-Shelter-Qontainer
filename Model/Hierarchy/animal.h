#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class IAnimal {

public:
    virtual ~IAnimal() = default;
    virtual int Id() const = 0;
    virtual std::string Name() const = 0;
    virtual int Age() const = 0;
    virtual std::string Breed() const = 0;
    virtual std::string Adopted() const = 0;
    virtual std::string Gender() const = 0;
};

class Animal : public IAnimal {

public:
    Animal(int id, std::string name, int age, std::string breed, std::string adopted, std::string gender);
    ~Animal() override;
    int Id() const override;
    std::string Name() const override;
    int Age() const override;
    std::string Breed() const override;
    std::string Adopted() const override;
    std::string Gender() const override;
    virtual std::string type() const = 0;
    virtual std::string vaccines() const = 0;
    virtual std::string speak() const = 0;
    virtual double costOfcare() const = 0;

protected:
    int _id;
    std::string _name;
    int _age;
    std::string _breed;
    std::string _adopted;
    std::string _gender;
    static double _baseCost;
};

#endif
