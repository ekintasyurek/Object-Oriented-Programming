//////////////////////////////////
/*          <Ekin Tasyurek>         */
/*          <150190108>           */
//////////////////////////////////
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string newName,string newSurname){
    name=newName;
    surname=newSurname;
}


Passenger::Passenger(string newName,string newSurname, int newCash):Person(newName, newSurname){
    cash=newCash;
    ticket=false;

    if(newCash<0){
        cash=0;
        cout<<"Passenger cash can’t be negative. It is set to 0."<<endl;
    }
}

Passenger::Passenger(string newName,string newSurname):Person(newName, newSurname){
    cash=0;
    ticket=false;

}

bool Passenger::buyTicket(int newTicketPrice) {
    if(cash>=newTicketPrice){
        cash=cash-newTicketPrice;
        ticket=true;
    }
    else{
        ticket=false;
    }

    return ticket;
}


Astronaut::Astronaut(string newName, string newSurname, int newNumMissions):Person(newName, newSurname) {
    numMissions= newNumMissions;

    if(newNumMissions<0){
        cout<<"Number of missions that astronaut completed can't be negative. It is set to 0."<<endl;
        numMissions=0;
    }
}

Astronaut::Astronaut(string newName, string newSurname):Person(newName, newSurname) {
    numMissions=0;
}

void Astronaut::completeMission() {
    numMissions++;
}

