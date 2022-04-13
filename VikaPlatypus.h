#ifndef VIKAPLATYPUS_H
#define VIKAPLATYPUS_H
#include "Platypus.h"
class VikaPlatypus : public Platypus{
    unsigned inventory;
public:
    VikaPlatypus();
    VikaPlatypus(float weight, short age, string name, char gender);
    const Platypus & hatch() override;
    float RandW() const override;
    void eat() override;
    unsigned getInv() const;
    void setInv(unsigned newInv);
    unsigned RandInv() const;
    unsigned RandMinus() const;
    void CheckInv() const;
    void fight(VikaPlatypus & other);
    void Gym();
    };
#endif