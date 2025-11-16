//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_DATE_H
#define HOTEL_MANAGEMENTSYSTEM_DATE_H

#include <iostream>

using namespace std;
struct filecar {
    int num;
    int num2;
    int num3;
};

class Date {
public:
    int day;
    int month;
    int year;

    Date operator-(Date &cardate) {
        Date newdate;

        newdate.day = day - cardate.day;
        newdate.month = month - cardate.month;
        newdate.year = year - cardate.year;
        return newdate;

    }


    friend istream &operator>>(istream &inp, Date &da) {
        inp >> da.day;

        inp >> da.month;

        inp >> da.year;
        return inp;
    }


    friend ostream &operator<<(ostream &out, Date &da) {
        out << da.day << ' ' << da.month << ' ' << da.year;
    }


    int calculatedays(Date day2) {
        int numof = 0;
        numof += day2.day - day;
        numof += (day2.month - month) * 30;
        numof += (day2.year - year) * 367;
        return numof;


    }


};


#endif //HOTEL_MANAGEMENTSYSTEM_DATE_H
