#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
int main(){
    BasicPlatypus bp;
    NiggaPlatypus np;
    bp.hatch();
    bp.eat();
    bp.PrintInf();
    np.hatch();
    np.eat();
    np.PrintInf();
    np.fight(bp);
    bp.PrintInf();
    np.PrintInf();
}
