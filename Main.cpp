#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
int main(){
    Platypus *p, *p1;
    BasicPlatypus bp;
    p = &bp;
    p->hatch();
    p->PrintInf();
}
