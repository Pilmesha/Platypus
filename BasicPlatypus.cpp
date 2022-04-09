#include "Platypus.h"
#include "BasicPlatypus.h"

BasicPlatypus::BasicPlatypus(){
    setType("Basic");
}
BasicPlatypus::BasicPlatypus(float weight, short age, string name, char gender){
    setWeight(weight);
    setHealth(100);
    setEnergy(0);
    setAge(age);
    setName(name);
    setGender(gender);
    setType("Basic");
    alive = true;
    mutant = false;
}


BasicPlatypus::operator NiggaPlatypus()const{
    return NiggaPlatypus(getWeight(), getAge(), getName(), getGender());
}


const Platypus &BasicPlatypus::hatch(){
    cout << "Basic platypus has been born" << endl;
    alive = true;
    mutant = false;
    setHealth(100);
    srand(time(0));    
    setWeight(RandW());
    if(rand() % 2 == 1) setGender('f');
    else setGender('m');
    cout << "Name the platypus? Y/N ";
    char c;
    cin >> c;
    if(c == 'Y' || c == 'y'){
        cout << "\nEnter the name: ";
        string n;
        cin >> n;
        setName(n);
    } else setName(RandName());
    return *this;
}