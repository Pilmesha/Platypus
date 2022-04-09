#include "Platypus.h"
class NiggaPlatypus : public Platypus{
public:
    NiggaPlatypus();
    NiggaPlatypus(float weight, short age, string name, char gender);
    NiggaPlatypus(const Platypus &BasicPlatypus);
    const Platypus &hatch();
    void RunNiggaRun() override;
    void fight(Platypus & other) override;
    virtual const Platypus &attack(Platypus & other_platypus) override;
};