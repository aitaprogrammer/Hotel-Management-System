//
// Created by abc1 on 3/23/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_BILLS_H
#define HOTEL_MANAGEMENTSYSTEM_BILLS_H
#include "Customer.h"
#include <iostream>
using namespace std;
template  <class type>
class Bills {
public:

    Customer *cus;
    type totalprofit;

void displaypastbills(){
        type profit=0;
        bool test=0;
        ifstream file("pastcustomers.txt");
        int testid=0;
        while(!file.eof()){
            file>>*cus;
            file>>profit;
            if(cus->id!=testid){
                testid=cus->id;
                cout<<endl<<cus->id<<endl<<cus->name;
                test=1;
                cout<<"\nAmount paid: "<<profit;
            cout<<"\n\n";
            }
        }
        if(test== false){

            cout<<"\nNO Past bills\n";
        }
        file.close();
    }


    type calculatetotalprofit(){
totalprofit=0;
type profit=0;
int testid=0;
        ifstream file("pastcustomers.txt");

        while(!file.eof()){
            file>>*cus;
            file>>profit;
            if(cus->id!=testid){
            totalprofit+=profit;
            }
        }
        file.close();
        return  totalprofit;
    }



};


#endif //HOTEL_MANAGEMENTSYSTEM_BILLS_H
