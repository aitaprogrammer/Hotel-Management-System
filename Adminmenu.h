//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_ADMINMENU_H
#define HOTEL_MANAGEMENTSYSTEM_ADMINMENU_H

#include "Room.h"
#include <iostream>

using namespace std;

#include "Complain.h"
#include "Employee.h"
#include "Customer.h"
#include "Bills.h"
#include <fstream>


class Adminmenu {
public:
    Bills<double> bill;

    Employee *emp;
    Room *room;
    Complain *comp;
    Customer *cus;

    void addemp() {

//        cout<<"\nEnter Employee info\n";
//       cin>>*emp;
//       ofstream file("employees.txt");
//       emp->idsetter++;
//       emp->id=emp->idsetter;
//
//       file<<emp->name<<" "<<emp->cnic<<" "<<emp->dateborn<<" "<<emp->id<<" "<<emp->numofcomps<<endl;
//            file.close();


    }
    void print_avilable_room(){
 bool xy=1;
        ifstream  inFile("availablerooms.txt", ios::in);

    void print_avilable_room() {

        ifstream inFile("avilablerooms.txt", ios::in);

        if (!inFile) {
            cout << "Error: Could not open file." << endl;
            return;
        }


        while (inFile >> *room) {
            cout<<"\n_________________________________________________\n";
          xy=0;
            room->printroomdetails();
            cout<<"\n_________________________________________________\n";

        }
        if(xy==1){
            cout<<endl<<"No avilable Room \n";
        while (inFile >> room->id >> room->capacity >> room->type) {
            cout << "ID: " << room->id << endl;
            cout << "Number of Persons: " << room->capacity << endl;
            cout << "TYPE " << room->type << endl << endl;
        }

        inFile.close();
        return;
    }



    void seealloccurooms(){
bool xy=1;
        ifstream  inFile("occupiedrooms.txt", ios::in);

        if (!inFile) {
            cout << "Error: Could not open file." << endl;
            return ;
        }


        while (inFile >> *room>>*cus) {
            cout<<"\n_________________________________________________\n";
          xy=0;
            room->printroomdetails();
            cout<<"\n_________________________________________________\n";

        }
        if(xy==1){
            cout<<"\nNo Room ocuupuied\n";
        }
        inFile.close();
    }


    void addroom() {
        ofstream file("availablerooms.txt", ios::app);
        cout << "\nEnter room capacity\n";
        cin >> room->capacity;
        cout << "enter room type";
        cin >> room->type;
        cout << "enter room day rate ";
        cin >> room->dayrate;
        Room::idsetter++;
        room->id = Room::idsetter;
        file << *room;
        file.close();

        cout << "\nSuccesfully added room with ID " << room->id;
    }


    void emptyroom(){
        int id;
        bool test=0;
        cout<<"enter the room id from which you want to get customer out";
        cin>>id;
        ifstream file("occupiedrooms.txt");
        while(!file.eof()){
            file>>*room;
            file>>*cus;
            if(room->id==id){
                test=1;
            }
        }
        file.close();
        if(test==0){
            cout<<"\nThis room is not occupuied or not exsists\n";
        }else {

            int idcar=0,idcar2=0;
            ifstream file2("occupiedrooms.txt");
            ofstream pastcus("pastcustomers.txt",ios::app);
            ofstream avaroom("availablerooms.txt",ios::app);
            ofstream temp("temp.txt");

            while(!file2.eof()){
                file2>>*room;
                file2>>*cus;
                if(cus->id!=idcar&&room->id!=idcar2){
                    idcar2=room->id;
                    idcar=cus->id;
                    if(room->id!=id){
                        temp<<*room<<" ";
                        temp<<*cus;
                    }else if(room->id==id){
                        pastcus<<*cus<<"  "<<0<<"  ";
                        avaroom<<*room;
                        cout<<"\nThe Customer finally exited.\n";
                    }


                }}
            pastcus.close();
            temp.close();
            avaroom.close();
            file2.close();


            remove("occupiedrooms.txt");
            ofstream writer("occupiedrooms.txt");
            ifstream tempreader("temp.txt");
            idcar=0;
            idcar2=0;

            while(!tempreader.eof()){
                tempreader>>*room;
                tempreader>>*cus;
                if(idcar!=cus->id&&room->id!=idcar2){
                    idcar=cus->id;
                    idcar2=room->id;
                    writer<<*room<<" ";
                    writer<<*cus;

                }}
            tempreader.close();
            remove("temp.txt");

        }

    }


    void printpastbills(){
        bill.displaypastbills();
    }

    void displayprofit(){
        double car=bill.calculatetotalprofit();
        cout<<"\nTotal Profit made by the Hotal is "<<car<<endl;
    }







};


#endif //HOTEL_MANAGEMENTSYSTEM_ADMINMENU_H
