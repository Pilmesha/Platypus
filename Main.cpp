#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
#include "VikaPlatypus.h"
int main(){
    VikaPlatypus vp;
    vp.hatch();
    vp.setInv(4);
    vp.CheckInv();
    for(int i = 0; i < 2; i++)
        vp.Gym();
    vp.CheckInv();
    vp.PrintInf();
    VikaPlatypus irishka;
    irishka.hatch();
    irishka.eat();
    irishka.Gym();
    irishka.Gym();
    irishka.PrintInf();
    irishka.fight(vp);
    irishka.PrintInf();
    vp.PrintInf();
    NiggaPlatypus np;
    np.hatch();
    np.PrintInf();
    np.RunNiggaRun();
    np.RunNiggaRun();
    np.RunNiggaRun();
    np.PrintInf();
}
