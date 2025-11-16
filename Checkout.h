//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_CHECKOUT_H
#define HOTEL_MANAGEMENTSYSTEM_CHECKOUT_H

#include  <iostream>

using namespace std;

#include "Room.h"
#include "Customer.h"

class Checkout {

public:
    Room *roo;
    Customer *cus;


    void checkout(Date &date) {
        int id;
        int idcar = 0, idcar2 = 0;
        bool test = 1;
        cout << "enter customer id to exit: ";
        cin >> id;
        ifstream file("occupiedrooms.txt");
        ofstream moneymatters("finance.txt", ios::app);

        while (!file.eof() && test == 1) {
            file >> *roo;
            file >> *cus;
            if (cus->id == id) {
                test = 0;
            }

        }
        file.close();
        if (test == 0) {



    void checkout(Date &date){
      int id;
        int idcar=0,idcar2=0;
      bool test=1;
        cout<<"enter customer id to exit: ";
      cin>>id;
      ifstream file("occupiedrooms.txt");
            ifstream file2("occupiedrooms.txt");
            ofstream pastcus("pastcustomers.txt", ios::app);
            ofstream avaroom("availablerooms.txt", ios::app);
            ofstream temp("temp.txt");

            idcar = cus->id;
            idcar2 = roo->id;
            while (!file2.eof()) {
                file2 >> *roo;
                file2 >> *cus;
                if (cus->id != idcar && roo->id != idcar2) {
                    idcar2 = roo->id;
                    idcar = cus->id;
                    if (cus->id != id) {
                        temp << *roo << " ";
                        temp << *cus;
                    } else if (cus->id == id) {
                        Date cd = roo->daterented;
                        int billam = cd.calculatedays(date);
                        billam *= roo->dayrate;
                        if (billam == 0) {
                            billam = 10;
                        }


                        cout << "\n\nBill of $" << billam;
                        moneymatters << billam << "  ";
                        pastcus << *cus;
                        avaroom << *roo;
                        cout << "\nThe Customer finally exited.\n";
                    }


                }
            }
            pastcus.close();
            avaroom.close();
            file2.close();
            temp.close();
            remove("occupiedrooms.txt");
            ofstream writer("occupiedrooms.txt");
            ifstream tempreader("temp.txt");
            idcar = 0;
            idcar2 = 0;

            while (!tempreader.eof()) {
                tempreader >> *roo;
                tempreader >> *cus;
                if (idcar != cus->id && roo->id != idcar2) {
                    idcar = cus->id;
                    idcar2 = roo->id;
                    writer << *roo << " ";
                    writer << *cus;

                }
            }
            tempreader.close();
            remove("temp.txt");

                  cout<<"\n\nBill of $"<<billam;
                  pastcus<<*cus<<"  "<<billam<<"  ";
                  avaroom<<*roo;
                  cout<<"\nThe Customer finally exited.\n";
              
            moneymatters.close();

            writer.close();

          }
          pastcus.close();
          avaroom.close();
          file2.close();
          temp.close();
          remove("occupiedrooms.txt");
          ofstream writer("occupiedrooms.txt");
          ifstream tempreader("temp.txt");
          idcar=0;
          idcar2=0;

          while(!tempreader.eof()){
              tempreader>>*roo;
              tempreader>>*cus;
              if(idcar!=cus->id&&roo->id!=idcar2){
                  idcar=cus->id;
                  idcar2=roo->id;
             writer<<*roo<<" ";
              writer<<*cus;

          }}
          tempreader.close();
          remove("temp.txt");


          writer.close();

      }else {
          cout<<"\nThis id is not staying in the hotel\n";
      }
        else {
            cout << "\nThis id is not staying in the hotel\n";
        }
        remove("temp.txt");
}

    

};


#endif //HOTEL_MANAGEMENTSYSTEM_CHECKOUT_H
