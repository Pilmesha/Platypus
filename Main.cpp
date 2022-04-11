#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
int main(){
    Platypus *p, *p1;
    BasicPlatypus bp, np;
    p = &bp;
    p1 = &np;
    p->hatch();
    p->eat();
    p->eat();
    p1->hatch();
    p1->eat();
    p1->fight(*p);
    p->PrintInf();
    p1->PrintInf();
}
