#include "Platypus.h"
#include "BasicPlatypus.h"

int main(){
    Platypus *p, *p1;
    BasicPlatypus P(0.69, 3, "Keke", 'm');
    NiggaPlatypus P1(0.69, 3, "NigGio", 'm');
    p1 = &P1;
    p = &P;
    p->eat();
    p->PrintInf();
    p1->eat();
    p1->PrintInf();
    p1->fight(*p);
    p1->PrintInf();
    p->PrintInf();
}
