#include "VikaPlatypus.h"

VikaPlatypus::VikaPlatypus(){
    setType("Vika");
}
VikaPlatypus::VikaPlatypus(float weight, short age, string name, char gender){
    setWeight(weight);
    setHealth(100);
    setEnergy(5);
    setAge(age);
    setName(name);
    setGender(gender);
    setType("Vika");
    alive = true;
    mutant = false;
}
void VikaPlatypus::CheckInv() const{
    cout << "You have " << getInv() << " xaxhapuri in your inventory." << endl;
}
unsigned VikaPlatypus::RandMinus()const{
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(1, 5);
    return gen(dre);
}
void VikaPlatypus::eat(){
    if(alive && getInv() != 0){
    cout << getName() << " is eating Xachapuri...." << endl;
    float w = getWeight();
    setWeight(w += (w * RandMinus()));
    setInv(inventory -= RandMinus());
    
    default_random_engine dre(time(0));
    uniform_int_distribution<int> genEnergy(10, 20);
    default_random_engine dre1(time(0));
    uniform_int_distribution<int> genHealth(20, 40);
    if(getEnergy() != MAX_ENERGY) {
        unsigned e = getEnergy();
        setEnergy(e += genEnergy(dre));
    if(getEnergy() > MAX_ENERGY) setEnergy(MAX_ENERGY);
    }

    if(getHealth() != MAX_HEALTH){
        short h = getHealth();
    setHealth(h +=  genHealth(dre1));
    }
    if(getHealth() > MAX_HEALTH) setHealth(MAX_HEALTH);
    } else if(!alive) cout << "Dead Vika can not eat" << endl;
    else cout << "You have no Xachapuri in inventory"<< endl;
}
float VikaPlatypus::RandW() const {
    default_random_engine dre(time(0));
    uniform_real_distribution<float> gen(1.0f, 5.0f);
    for(int i = 0; i < 5; i++) gen(dre);
    return gen(dre);
}
unsigned VikaPlatypus::RandInv() const{
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(5, 100);
    return gen(dre);
}
void VikaPlatypus::setInv(unsigned newinv){
    this->inventory = newinv;
}
unsigned VikaPlatypus::getInv() const{
    return inventory;
}
const Platypus &VikaPlatypus::hatch(){
    cout << "Vika has been born" << endl;
    alive = true;
    mutant = false;
    setHealth(100);
    setEnergy(5);
    srand(time(0));    
    setWeight(RandW());
    setName("Vika");
    setInv(RandInv());
    int randG = rand() % 2;
    if(randG == 1) setGender('f');
    else setGender('m');
    cout << "Vika wants Xachapuri!!!"<< endl;
    cout << "Do you want to feed Vika? Y/N ";
    char c;
    cin >> c; 
    if(c == 'y' || c == 'Y'){
        this->eat();
    } else {
        isDead(*this);
        cout << "Vika died from lack of Xaxhapuri" << endl;
    }
    return *this;
}
void VikaPlatypus::fight(VikaPlatypus & other){
        const float fight_ratio = ((this->getWeight()*this->getEnergy())/(other.getWeight()*other.getEnergy()));
    if((this->alive && other.isAlive()) && (this->getEnergy() != 0 && other.getEnergy() != 0)){
       while(this->getHealth() > 0 && other.getHealth() > 0){
       this->attack(other);
       other.attack(*this);
       }
    if(other.getHealth() <= 0){
        isDead(other);
        cout << this->getName() << " won"<< endl;
        this->setInv(inventory += other.getInv());
        other.setInv(0);
        this->RandEnergy();
    } else if(this->getHealth() <= 0){
        isDead(*this);
        cout << other.getName() << " won" << endl;
        other.setInv(other.inventory += this->getInv());
        this->setInv(0);
        other.RandEnergy();
    }
    } else 
    if(this-> getEnergy() == 0 || other.getEnergy() == 0) cout << "One of the platypuses do not have enough energy" << endl;
    else cout << "One of the platypuses are dead" << endl;
}
void VikaPlatypus::Gym(){
    if(alive && getEnergy() > 0){
    cout << "Vika went to the gym" << endl;
    RandEnergy();
    setInv(RandInv());
    } else cout << "Dead Vika can not go to gym" << endl;

}