#include "NiggaPlatypus.h"

NiggaPlatypus::NiggaPlatypus(){
    setType("Nigga");
}
NiggaPlatypus::NiggaPlatypus(float weight, short age, string name, char gender){
    setWeight(weight);
    setHealth(100);
    setEnergy(0);
    setAge(age);
    setName(name);
    setGender(gender);
    setType("Nigga");
    alive = true;
    mutant = false;
}
const Platypus &NiggaPlatypus::hatch(){
    cout << "Black platypus has been born" << endl;
    alive = true;
    mutant = false;
    setHealth(100);
    srand(time(0));    
    setWeight(RandW());
    int randG = rand() % 2;
    if(randG == 1) setGender('f');
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
void NiggaPlatypus::RunNiggaRun(){
    if(this->alive){
    cout << "Nigga started running"<< endl;
    {
    unsigned en = getEnergy();
    setEnergy(en -= en* 0.5);

    float w = getWeight();
    setWeight(w -= w*0.5);
    }
    } else cout << "Dead Nigga can not run" << endl;
}
void NiggaPlatypus::fight(Platypus &other){
    if((this->alive && other.isAlive()) && (this->getEnergy() != 0 && other.getEnergy() != 0)){
       while(this->getHealth() > 0 && other.getHealth() > 0){
       this->attack(other);
       this->attack(other);
       other.attack(*this);
       }
       if(other.getHealth() <= 0){
           cout << this->getName() << " won" << endl;
           other.setAlive(false);
           other.setHealth(0); other.setEnergy(0);
           this->setHealth(abs(getHealth()));
           this->RandEnergy();
       } else if(this->getHealth() <= 0){         
            cout << other.getName() << " won" << endl;
           this->alive = false;
           this->setHealth(0);this->setEnergy(0);
           other.RandEnergy();
       }
}
}
const Platypus &NiggaPlatypus::attack(Platypus & other_platypus){
    short fight_ratio = ((this->getWeight()*this->getEnergy())/(other_platypus.getWeight()*other_platypus.getEnergy()));
    default_random_engine dre(time(0));
    uniform_int_distribution<short> gen(1, 5);
    cout << this->getName() << " attacks " << other_platypus.getName() << endl;
    short oh = other_platypus.getHealth();
    other_platypus.setHealth(oh -= (gen(dre) * fight_ratio));
    return other_platypus;
}