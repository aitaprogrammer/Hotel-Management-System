//
// Created by abc1 on 3/21/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_EMPLOYEE_H
#define HOTEL_MANAGEMENTSYSTEM_EMPLOYEE_H

#include "Peaple.h"
#include <fstream>


class Employee : public Peaple {

public:

    Employee() {
        ifstream file("setup.txt");
        file >> idsetter;
        file >> idsetter;
        file.close();

    }

    static int idsetter;
    int id;
    int numofcomps;

    void seeempinfo();

    friend istream &operator>>(istream &inp, Employee &emp) {
        cout << "Enter name ";
        inp >> emp.name;
        cout << "cnic";
        inp >> emp.cnic;
        cout << "Date born";
        inp >> emp.dateborn;
        return inp;


    }

    ~Employee() {
        filecar car;
        ifstream file("setup.txt");
        file >> car.num;
        file >> car.num2;
        file >> car.num3;
        file.close();
        ofstream file2("setup.txt");
        file2 << car.num << " " << idsetter << " " << car.num3 << endl;
        file2.close();
    }

};


#endif //HOTEL_MANAGEMENTSYSTEM_EMPLOYEE_H
