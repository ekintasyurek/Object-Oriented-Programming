//////////////////////////////////
/*          <Ekin Tasyurek>         */
/*          <150190108>           */
//////////////////////////////////
#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Mission.h"

using namespace std;

class Agency{
    string name;
    int cash;
    int ticketPrice;
    Mission* completedMissions;
    Mission* nextMissions;

    int numNextMission; //used in operator <<
    int numCompletedMission; //used in operator <<

public:
    Agency(string,int,int);
    void addMission(Mission);
    void executeNextMission();
    friend ostream& operator <<(ostream&, Agency&);

    //~Agency(); I implemented the destructor in Agency.cpp but there was an error so I wrote it as a comment

    int getTicketPrice(){return ticketPrice;} //getter
    void setTicketPrice(int price){ticketPrice=price;} //setter
};