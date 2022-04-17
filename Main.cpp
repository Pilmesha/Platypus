#include "Platypus.h"
#include "BasicPlatypus.h"
#include "NiggaPlatypus.h"
#include "VikaPlatypus.h"
int main(){
    VikaPlatypus vp;
    vp.hatch();
    vp.setInv(4);
    vp.CheckInv();
    
    for(int i = 0; i < 5; i++) vp.eat();
    vp.Gym();
    vp.CheckInv();
    vp.PrintInf();
    /*
    while(1){
        Platypus *p; Platypus *p1;
        BasicPlatypus bp; NiggaPlatypus np; VikaPlatypus vp;
        cout << "Welcome to platypus farm" << endl;
        cout << "Choose your platypus: " << endl;
        cout << "1. BasicPlatypus"
        <<"\n2. NiggaPlatypus"
        <<"\n3. VikaPlatypus" 
        << "\n>> ";
        short c;
        cin >> c;
        switch(c){
            case 1: 
        p = &bp; 
        p->hatch();
        cout << "Choose what to do with the platypus: " << endl;
        cout << "1. Eat"
        <<"\n2.Fight with another platypus" 
        <<"\nPrint info about the platypus"
        <<"\n>> ";
        short c1; cin >> c1;
        switch (c1)
        {
        case 1: p->eat(); break;
        case 2: cout << "Choose another platypus" << endl;
                cout << "1. BasicPlatypus"
        <<"\n2. NiggaPlatypus"
        <<"\n3. VikaPlatypus" 
        << "\n>> ";
        short c2;
        cin >> c2;
        switch(c2){
            case 1: p1 = &bp; p1->hatch(); break;
            case 2: p1 = &np; p1->hatch();  break;
            case 3: p1 = &vp; p1->hatch(); break;
        }
        }
        case 3: p->PrintInf();
            case 2: p = &np; break;
            case 3: p = &vp; break;
        }
    }*/
    
}
