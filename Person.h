//////////////////////////////////
/*          <Ekin Tasyurek>         */
/*          <150190108>           */
//////////////////////////////////
#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Person{
protected:
    string name;
    string surname;

public:
    Person(string,string);

    string getName(){return name;} //getter
    string getSurname(){return surname;} //getter
};

class Passenger:public Person {
    int cash;
    bool ticket;

public:
    Passenger(string,string,int);
    Passenger(string,string);
    bool buyTicket(int);

    Passenger* next= nullptr;
    Passenger* tail=nullptr;

    bool getTicket(){return ticket;} //getter
};

class Astronaut:public Person{
    int numMissions;

public:
    Astronaut(string,string,int);
    Astronaut(string,string);
    void completeMission();

    Astronaut* next=nullptr;
    Astronaut* tail=nullptr;

    int getNumMissions(){return numMissions;} //getter
};

