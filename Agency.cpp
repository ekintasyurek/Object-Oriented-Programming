//////////////////////////////////
/*          <Ekin Tasyurek>         */
/*          <150190108>           */
//////////////////////////////////
#include <iostream>
#include "Agency.h"

Agency::Agency(string newName,int newCash,int newTicketPrice) {
    name=newName;
    cash=newCash;
    ticketPrice=newTicketPrice;
    completedMissions= nullptr;
    nextMissions= nullptr;
    numNextMission=0;
    numCompletedMission=0;

    if(newTicketPrice<0){
        cout<<"Ticket price can't be negative. It is set to 0."<<endl;
        ticketPrice=0;
    }
}

/*Agency::~Agency() {
    Mission* tempCompleted=this->completedMissions;
    Mission* tempCompleted1= nullptr;

    while(tempCompleted){
        tempCompleted1=tempCompleted->next;
        free(tempCompleted);
        tempCompleted=tempCompleted1;
    }

    Mission* tempNext=this->nextMissions;
    Mission* tempNext1= nullptr;

    while(tempNext){
        tempNext1=tempNext->next;
        free(tempNext);
        tempNext=tempNext1;
    }

    completedMissions= nullptr;
    nextMissions= nullptr;
}*/

void Agency::addMission(Mission m) {

    if(nextMissions== nullptr){
        nextMissions=&m;
        nextMissions->tail=&m;
    }
    else {
        nextMissions->tail->next=&m;
        nextMissions->tail=&m;
    }

    numNextMission++;
}

void Agency::executeNextMission() {


    if(nextMissions== nullptr){
        cout<<"No available mission to execute!"<<endl;
    }

    else {

        Mission *temp=nextMissions;

        temp->executeMission();

        cash = cash + temp->calculateProfit(getTicketPrice());

        if(nextMissions->next== nullptr){
            nextMissions= nullptr;
        }
        else{
            nextMissions=nextMissions->next;
        }

        if(temp->getCompleted()){

            numCompletedMission++;
            numNextMission--;

            if(completedMissions== nullptr){
                completedMissions=temp;
                completedMissions->tail=completedMissions;
                completedMissions->tail->next= nullptr;
            }
            else{
                completedMissions->tail->next=temp;
                completedMissions->tail=temp;
                completedMissions->tail->next= nullptr;
            }
        }
        else{
            if(nextMissions==nullptr){
                nextMissions=temp;
                nextMissions->tail=temp;
                nextMissions->tail->next= nullptr;
            }
            else{
                nextMissions->tail->next=temp;
                nextMissions->tail=temp;
                nextMissions->tail->next= nullptr;
            }
        }
    }
}

ostream& operator<<(ostream& out, Agency& a) {
    out<<"Agency name: "<<a.name<<", Total cash: "<<a.cash<<", Ticket Price: "<<a.ticketPrice<<endl;
    out<<"Next Missions:"<<endl;


    if(a.nextMissions== nullptr){
        out<<"No missions available."<<endl;
    }
    else {

        Agency *b= new Agency(" ", 0,0);
        *b=a;

        for (int i = 0; i <b->numNextMission; i++) {
            out << "Mission number " << b->nextMissions->getMissionNumber() << " Mission name: "
                << b->nextMissions->getName() << " Cost: " << b->nextMissions->getCost() << endl;
            b->nextMissions = b->nextMissions->next;
        }

        delete b;
    }
    out<<"Completed Missions:"<<endl;

    if(a.completedMissions== nullptr){
        out<<"No missions completed before."<<endl;
    }
    else {

        Agency *b= new Agency(" ", 0,0);
        *b=a;

        for (int i = 0; i <b->numCompletedMission; i++) {
            out << "Mission number " << b->completedMissions->getMissionNumber() << " Mission name: "
                << b->completedMissions->getName() << " Cost: " << b->completedMissions->getCost() << endl;
            b->completedMissions = b->completedMissions->next;
        }

        delete b;
    }
    return out;
}