//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_CUSTOMER_H
#define HOTEL_MANAGEMENTSYSTEM_CUSTOMER_H

#include "Peaple.h"
#include <fstream>
#include "Date.h"

class Customer : public Peaple {
public:


    Customer() {
        ifstream file("setup.txt");
        file >> idsetter;
        file >> idsetter;
        file >> idsetter;
        file.close();
    }


    static int idsetter;
    int id;


    friend ostream &operator<<(ostream &out, Customer &cus) {   //for writing to file
        out << cus.id << " " << cus.name << " " << cus.cnic << " " << cus.dateborn << endl;
        return out;

    }

    friend istream &operator>>(istream &out, Customer &cus) {     //for reading from file
        out >> cus.id >> cus.name >> cus.cnic >> cus.dateborn;
        return out;

    }


    void inputdetails() {          //for inputing on terminal

        cout << "enter name";
        cin >> name;
        cout << "enter cnic";
        cin >> cnic;
        cout << "enter data born";
        cin >> dateborn;
        id = ++idsetter;
        cout << "\n customer id is " << id << endl << endl;
    }


    void printdetails() {
        cout << "\nName: " << name;
        cout << "\ncnic: " << cnic;
        cout << "\nDataborn: " << dateborn;
    }


    ~Customer() {
        filecar car;
        ifstream file("setup.txt");
        file >> car.num;
        file >> car.num2;
        file >> car.num3;
        file.close();
        ofstream file2("setup.txt");
        file2 << car.num << " " << car.num2 << " " << idsetter << endl;
        file2.close();


    }


};


#endif //HOTEL_MANAGEMENTSYSTEM_CUSTOMER_H
