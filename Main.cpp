#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
#include "VikaPlatypus.h"
int main(){
    VikaPlatypus v(2.3, 4, "Vika", 'f');
    VikaPlatypus v1(2.69, 6, "Vikka", 'f');
    v.Gym();
    v1.Gym();
    v.CheckInv();
    v1.CheckInv();
    v1.fight(v);
    v1.CheckInv();
    v.CheckInv();
    v.PrintInf();
    v1.PrintInf();
}
