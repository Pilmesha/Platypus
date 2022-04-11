#ifndef NIGGAPLATYPUS_H
#define NIGGAPLATYPUS_H
#include "Platypus.h"
#include "BasicPlatypus.h"
class NiggaPlatypus : public Platypus{
public:
    NiggaPlatypus();
    NiggaPlatypus(float weight, short age, string name, char gender);
    const Platypus &hatch();
    void RunNiggaRun() override;
    void fight(Platypus & other) override;
    virtual const void attack(Platypus & other_platypus) override;
};
#endif