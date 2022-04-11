#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
int main(){
    Platypus *p, *p1;
    BasicPlatypus bp(1, 6, "momo", 'm'), np(0.1, 5, "keke", 'm');
    p = &bp;
    p1 = &np;
    p->eat();
    p1->eat();
    p1->fight(*p);
    p->PrintInf();
    p1->PrintInf();
}
