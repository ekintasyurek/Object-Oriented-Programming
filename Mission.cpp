//////////////////////////////////
/*          <Ekin Tasyurek>         */
/*          <150190108>           */
//////////////////////////////////
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Mission.h"


Mission::Mission() {
    cost=0;
    faultProbability=0;
    crew= nullptr;
    passengers= nullptr;
    completed= false;
    name=" ";
    missionNumber=0;
    numPassengers=0;
}

Mission::Mission(string newName, int newCost,int newFaultProbability) {
    cost=newCost;
    faultProbability=newFaultProbability;
    crew= nullptr;
    passengers= nullptr;
    completed=false;
    incrementNumMission();
    missionNumber=numMissions;
    numPassengers=0;

    string letter=newName.substr(0,2);

    if(("AA"<=letter) && (letter<="ZZ") && (newName[2]=='-') && ('0'<=newName[3]) && (newName[3]<='9') && ('0'<=newName[4]) && (newName[4]<='9')){
        name=newName;
    }
    else{
        cout<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;
        name="AA-00";
    }
}

/*Mission::~Mission() {

    Passenger* tempPassenger=this->passengers;
    Passenger* tempPassenger1= nullptr;

    while(tempPassenger){
        tempPassenger1=tempPassenger->next;
        free(tempPassenger);
        tempPassenger=tempPassenger1;
    }

    Astronaut* tempCrew=this->crew;
    Astronaut* tempCrew1= nullptr;

    while(tempCrew){
        tempCrew1=tempCrew->next;
        free(tempCrew);
        tempCrew=tempCrew1;
    }

    passengers= nullptr;
    crew= nullptr;
}*/

void Mission::operator+=(Passenger* p) {

    if (p->getTicket()) {

        if(passengers== nullptr){
            passengers=p;
            passengers->tail=p;
            numPassengers++;
        }
        else {
            passengers->tail->next=p;
            passengers->tail=p;
            numPassengers++;
        }
    } else {
        cout << "Passenger " << p->getName() <<" "<< p->getSurname() << " does not have a valid ticket!" << endl;
    }
}

void Mission::operator+=(Astronaut* p) {

    if(crew== nullptr){
        crew=p;
        crew->tail=p;
    }
    else {
        crew->tail->next=p;
        crew->tail=p;
    }
}

bool Mission::executeMission() {
    int s1=rand()%100;
    if(s1<faultProbability){
        cout<<"MISSION "<<name<<" FAILED!"<<endl;
        cout<<"Agency reschedules the mission."<<endl;
        completed=false;
    }
    else{
        cout<<"MISSION "<<name<<" SUCCESSFUL!"<<endl;

        Astronaut *b=crew;

        while(b!=nullptr){
            b->completeMission();
            cout<<"Astronaut "<<b->getName()<<" "<<b->getSurname()<<" successfully completed "<<b->getNumMissions()<<" missions."<<endl;
            b=b->next;
        }
        completed=true;
    }
    return completed;
}

int Mission::calculateProfit(int ticketPrice) {
    if(completed){
        int money=numPassengers*ticketPrice;
        return (money-cost);
    }
    else{
        return (-cost);
    }
}