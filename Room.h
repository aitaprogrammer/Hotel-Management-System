//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_ROOM_H
#define HOTEL_MANAGEMENTSYSTEM_ROOM_H

#include <iostream>
#include <fstream>

using namespace std;

#include "Date.h"

class Room {
public:
    Room() {
        ifstream file("setup.txt");
        file >> idsetter;
        file.close();
    }

    int capacity;
    static int idsetter;
    int id;
    Date daterented;
    string type;
    double dayrate;

    friend ostream &operator<<(ostream &out, Room &cus) {       //for writing to file
        out << cus.id << " " << cus.capacity << " " << cus.type << " " << cus.dayrate << " " << cus.daterented << endl;
        return out;

    }


    friend istream &operator>>(istream &inp, Room &cus) {     //for reading from file
        inp >> cus.id >> cus.capacity >> cus.type >> cus.dayrate >> cus.daterented;
        return inp;
    }


    void printroomdetails() {          //for displaying to user

        cout << "\nID: " << id;
        cout << "\ncapacity: " << capacity;
        cout << "\nCategory: " << type;
        cout << "\nDay rate in $" << dayrate << endl << endl;
    }


    ~Room() {

        filecar car;
        ifstream file("setup.txt");
        file >> car.num;
        file >> car.num2;
        file >> car.num3;
        file.close();
        ofstream file2("setup.txt");
        file2 << idsetter << " " << car.num2 << " " << car.num3 << endl;
        file2.close();


    }
};


#endif //HOTEL_MANAGEMENTSYSTEM_ROOM_H
