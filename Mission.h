//////////////////////////////////
/*          <Ekin Tasyurek>         */
/*          <150190108>           */
//////////////////////////////////
#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Person.h"

using namespace std;

class Mission{
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed;
    Passenger* passengers; //head of the passengers linked list
    Astronaut* crew; //head of the crew linked list
    static int numMissions; //static

    int numPassengers; //used while calculating profit

public:
    Mission();
    Mission(string, int, int);

    //~Mission();  I implemented the destructor in Mission.cpp but there was an error so I wrote it as a comment

    void operator+=(Passenger*);//for adding a Passenger to the mission passenger list
    void operator+=(Astronaut*);//for adding an Astronaut to the mission crew list
    bool executeMission();
    int calculateProfit(int);

    Mission* next=nullptr;
    Mission* tail= nullptr;

    int getMissionNumber(){return missionNumber;} //getter
    int getNumMissions(){return numMissions;} //getter
    string getName(){return name;} //getter
    bool getCompleted(){return completed;} //getter
    int getCost(){return cost;} //getter
    void setName(string newName){

        string letter=newName.substr(0,2);

        if(("AA"<=letter) && (letter<="ZZ") && (newName[2]=='-') && ('0'<=newName[3]) && (newName[3]<='9') && ('0'<=newName[4]) && (newName[4]<='9')){
            name=newName;
        }
        else{
            cout<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;
            name="AA-00";
        }} //setter

    static void incrementNumMission(){numMissions++;} //for incrementing the number of missions everytime a new mission is added
};