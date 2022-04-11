#include "Platypus.h"

///Constuctors
Platypus::Platypus(){
    weight = 0.0f;
    age = 0.0f;
    name = '-';
    energy = 0;
    health = 0;
    gender = '-';
    type = "Undefined";
    alive = false;
    mutant = false;
    
}
Platypus::Platypus(float &weight, short &age, string &name, char &gender, string &type){
    this->weight = weight;
    this->age = age;
    this->name = name;
    this->energy = 0;
    this->health = 100;
    this->gender = gender;
    this->type = type;
    if(this->weight > MAX_WEIGHT){
        alive = false;
        health = 0;
        cout << name << " died from the overweight" << endl;
    } else {
        alive = true;
    }
    mutant = false;
}
Platypus::~Platypus() = default;


//Print function
void Platypus::PrintInf() const{
    cout << "*******Information about this platypus:*********\n";
    cout <<"Name: " << name 
    <<"\nAge: " << age << " months"
    <<"\nWeight: " << weight << " kg"
    <<"\nHealth: " << health << " hp"
    <<"\nEnergy: " << energy << " J"
    <<"\nType: " << type;
    if(gender == 'm' || gender == 'M'){
    cout <<"\nGender: Male";
    } else if(gender == 'f' || gender == 'F'){
    cout << "\nGender: Female";
    }
    else cout << "\nGender: Undefined";
    if(alive){
    cout << "\nStatus: Alive";
    } else cout << "\nStatus: Dead";
    if(mutant){
        cout << "\nIs Mutant";
    } else cout << "\nNot Mutant";
    cout << endl;
}



//Random generators for functions

float Platypus::RandW(){
    default_random_engine dre(time(0));
    uniform_real_distribution<float> gen(0.1f, 1.5f);
    for(int i = 0; i < 5; i++) gen(dre);
    return gen(dre);
}
string Platypus::RandName() const{
    ifstream ifsM("NamesM.txt"), ifsF("NamesF.txt");
    string name;
    vector <string> NamesVec;
    
    if(gender == 'm' || gender == 'M'){
        while(ifsM >> name)
        NamesVec.push_back(name);
    } else{
        while(ifsF >> name)
        NamesVec.push_back(name);
    }
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(0, NamesVec.size());
    return NamesVec[gen(dre)];
}
void Platypus::MutantChance(){
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(1,100);
    if(gen(dre) <=2) {
        mutant = true;
        cout << name << " became a mutant" << endl;
    }
}
void Platypus:: DeathChance(){
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(1,100);
    if(gen(dre) <= (weight*10)) {
        alive = false;
        cout << name << " died at the age of " << age << " months" << endl;
    }
}
void Platypus::RandEnergy(){
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(1, 5);
    for(int i = 0; i < 5; i++){
        gen(dre);
    }
    setEnergy(energy -= gen(dre));
}
string Platypus::RandType(){
    ifstream ifs("Platy_types.txt");
    string t;
    vector <string> T;
    while (ifs >> t) T.push_back(t);
    default_random_engine dre(time(0));
    uniform_int_distribution<int> gen(0, T.size()-1);
    gen(dre);
    return T[gen(dre)];
}

/////SETTERS/GETTERS
void Platypus::setWeight(float newWeight){
    this->weight = newWeight;
}
float Platypus::getWeight() const{
    return weight;
}
void Platypus::setAge(const float& newAge){
    this->age = newAge;
}
float Platypus::getAge() const{
    return age;
}
void Platypus::setName(const string& newName){
    this->name = newName;
}
void Platypus::setEnergy(const unsigned & newEnergy){
    this->energy = newEnergy;
}
string Platypus::getName()const{
    return name;
}
void Platypus::setGender(const char & newGender){
    this->gender = newGender;
}
char Platypus::getGender()const{
    return gender;
}
void Platypus::setHealth(const short & newHealth){
    this->health = newHealth;
}
unsigned Platypus::getEnergy() const{
    return energy;
}
short Platypus::getHealth() const{
    return health;
}
void Platypus::setAlive(bool st){
    alive = st;
}
bool Platypus::isAlive()const{
    return alive;
}
bool Platypus::isMutant()const{
    return mutant;
}
void Platypus::setType(const string & newType){
    this->type = newType;
}
string Platypus:: getType() const{
    return type;
}


//////MAIN FUNCTIONS
void Platypus::age_me(){
    if(alive){ 
        cout << "One month passed" << endl;
        setAge(++age);
        cout << "\nAge of the " << name << " now is "<< age << " months" << endl;
        MutantChance();
        DeathChance();
    } else;
}

void Platypus::eat(){
    if(alive){
    cout << name << " is eating...." << endl;
    setWeight(weight += (weight * RandW())); 
    default_random_engine dre(time(0));
    uniform_int_distribution<int> genEnergy(10, 20);
    default_random_engine dre1(time(0));
    uniform_int_distribution<int> genHealth(20, 40);

    if(getEnergy() != MAX_ENERGY) {
        setEnergy(energy += genEnergy(dre));
    if(getEnergy() > MAX_ENERGY) setEnergy(MAX_ENERGY);
    }

    if(health != MAX_HEALTH){
    setHealth(health +=  genHealth(dre1));
    if(getHealth() > MAX_HEALTH) setHealth(MAX_HEALTH);
    }
    if(weight > MAX_WEIGHT){
        alive = false;
        cout << name << " died from the overweight" << endl;
    }
    } else cout << "Dead platypus can not eat" << endl;
}

void Platypus::fight(Platypus & other){
   if((this->alive && other.alive) && (this->getEnergy() != 0 && other.getEnergy() != 0)){
       while(this->getHealth() > 0 && other.getHealth() > 0){
       this->attack(other);
       other.attack(*this);
       }
       if(other.getHealth() <= 0){
           cout << this->name << " won" << endl;
           other.alive = false;
           other.setHealth(0); other.setEnergy(0);
           this->RandEnergy();
       } else if(this->getHealth() <= 0){         
            cout << other.name << " won" << endl;
           this->alive = false;
           this->setHealth(0);this->setEnergy(0);
           other.RandEnergy();
       }
}
   else 
    if(this-> getEnergy() == 0 || other.getEnergy() == 0) cout << "One of the platypuses do not have enough energy" << endl;
    else cout << "One of the platypuses are dead" << endl;

}
const Platypus &Platypus::attack(Platypus & other_platypus){
    short fight_ratio = ((this->getWeight()*this->getEnergy())/(other_platypus.getWeight()*other_platypus.getEnergy()));
    default_random_engine dre(time(0));
    uniform_int_distribution<short> gen(1, 10);
    cout << this->name << " attacks " << other_platypus.name << endl;
    other_platypus.setHealth(other_platypus.health -= (gen(dre) * fight_ratio));
    return other_platypus;
}

void Platypus::RunNiggaRun(){
     cout << "Not Nigga Platypus can not run!!!" << endl;
}