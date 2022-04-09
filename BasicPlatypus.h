#include "Platypus.h"
#include "NiggaPlatypus.h"
class BasicPlatypus : public Platypus{
public:
    BasicPlatypus();
    BasicPlatypus(float weight, short age, string name, char gender);
    const Platypus &hatch() override;
    operator NiggaPlatypus() const;
};
