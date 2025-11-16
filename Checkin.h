

#ifndef HOTEL_MANAGEMENTSYSTEM_CHECKIN_H
#define HOTEL_MANAGEMENTSYSTEM_CHECKIN_H

#include <iostream>

using namespace std;

#include "Customer.h"
#include "Room.h"

class Checkin {
public:
    Room *room;
    Customer *cus;

void rentroom(Date &date) {
bool test=0;
ifstream avaroommv("availablerooms.txt");
int idtest=0;
    while(!avaroommv.eof()){
    avaroommv>>*room;
    if(!room){
        cout<<"\nNo Room found \n";
        return;
    }
    if(idtest!=room->id){
        test=1;
        idtest=room->id;
        room->printroomdetails();
    }

    }
avaroommv.close();

    ifstream avaroom("availablerooms.txt");
    ofstream temp("temp.txt");
    ofstream ocr("occupiedrooms.txt",ios::app);

    if(test==0){
        cout<<"\nNo Room Available\n";
        return;
    }
    test= false;
int id;
    cout<<"enter room id to BOOK ";
    cin>>id;
    while(!avaroom.eof()){
        avaroom>>*room;
        if(idtest!=room->id){
                 idtest=room->id;
            if(room->id!=id){
                temp<<*room;

            }else {
                test=1;
                cus->inputdetails();
                room->daterented=date;
                ocr<<*room;
                ocr<<*cus;}}}

    temp.close();
    ocr.close();
    avaroom.close();
    if(test==true){

        ifstream tempread("temp.txt");
        ofstream avawrite("availablerooms.txt");

        idtest=0;
        while(!tempread.eof()){
            tempread>>*room;
            if(idtest!=room->id){
                idtest=room->id;
                avawrite<<*room;}}}}
    void rentroom(Date &date) {
        bool test = 0;
        ifstream avaroommv("availablerooms.txt");
        int idtest = 0;
        while (!avaroommv.eof()) {
            avaroommv >> *room;
            if (idtest != room->id) {

                idtest = room->id;
                room->printroomdetails();
            }
        }
        avaroommv.close();
        ifstream avaroom("availablerooms.txt");
        ofstream temp("temp.txt");
        ofstream ocr("occupiedrooms.txt", ios::app);
        int id;
        cout << "enter room id to BOOK ";
        cin >> id;
        while (!avaroom.eof()) {
            avaroom >> *room;
            if (idtest != room->id) {
                idtest = room->id;
                if (room->id != id) {
                    temp << *room;

                } else {
                    test = 1;
                    cus->inputdetails();
                    room->daterented = date;
                    ocr << *room;
                    ocr << *cus;
                }
            }
        }

        temp.close();
        ocr.close();
        avaroom.close();
        if (test == true) {

            ifstream tempread("temp.txt");
            ofstream avawrite("availablerooms.txt");

            idtest = 0;
            while (!tempread.eof()) {
                tempread >> *room;
                if (idtest != room->id) {
                    idtest = room->id;
                    avawrite << *room;

                }
            }

            tempread.close();
            avawrite.close();
        } else cout << "\n|Cannot find room of this id|\n";


        remove("temp.txt");


    }
};


#endif //HOTEL_MANAGEMENTSYSTEM_CHECKIN_H
