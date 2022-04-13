#pragma once
#ifndef PLATYPUS_H
#define PLATYPUS_H
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
#define MAX_WEIGHT 10.0f
#define MAX_HEALTH 100
#define MAX_ENERGY 100
class Platypus{
private:
    float weight; //kilograms
    short age; //months
    string name; 
    unsigned energy; //j
    short health; //hp
    char gender; //f/m
    string type;
    protected:
    bool alive;
    bool mutant;
    
public:
    Platypus();
    Platypus(float &weight, short &age, string &name, char &gender, string &type);
    /////////////////////////////
    ~Platypus();
    /////////////////////////////
    void setWeight(float newWeigth);
    float getWeight() const;
    void setAge(const float& newAge);
    float getAge() const;
    void setName(const string& newName);
    string getName() const;
    void setEnergy(const unsigned & newEnergy);
    void setHealth(const short & newHealth);
    void setGender(const char & newGender);
    char getGender()const;
    unsigned getEnergy() const;
    short getHealth() const;
    void setAlive(bool st);
    bool isAlive() const;
    bool isMutant() const;
    void setType(const string & newType);
    string getType() const;
    void isDead(Platypus & p);
    /////////////////////////////
    void PrintInf() const;
    /////////////////////////////
    void age_me();
    virtual void fight(Platypus & other);
    //virtual const Platypus &attack(Platypus & other_platypus);
    virtual const Platypus & attack(Platypus & other_platypus);
    void eat();
    /////////////////////////////
    void DeathChance();
    void MutantChance();
    float RandW();
    string RandName() const;
    void RandEnergy();
    string RandType();
    /////////////////////////////
    virtual const Platypus &hatch() = 0;
    virtual void RunNiggaRun();
};
#endif