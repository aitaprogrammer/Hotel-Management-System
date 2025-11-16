//
// Created by abc1 on 3/23/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_MENU_H
#define HOTEL_MANAGEMENTSYSTEM_MENU_H
#include "Adminmenu.h"
#include "Customer.h"
#include "Room.h"
#include "Checkin.h"
#include "Checkout.h"
#include "Bills.h"
#include "Date.h"

class Menu {
static Menu *instance;
    Checkin ci;
    Date date;
    Checkout co;
    Room room;
    Customer cus;
    Adminmenu menu;
    Bills<double> bill;

    Menu(){
        int c;
        ifstream file("setup.txt");
        file>>c>>c>>c;
        file>>date;
        file.close();

ci.cus=&cus;
ci.room=&room;
co.cus=&cus;
co.roo=&room;
bill.cus=&cus;
menu.room=&room;


}


public:
   static Menu* getinstance(){
        if(instance== nullptr){
            instance=new Menu;
        }

       return  instance;
    }



    void checkin(){
        ci.rentroom(date);
    }


    void checkout(){
        co.checkout(date);
    }




    void Adminmenu(){
        bool test=true;
        string passcode,password;
        ifstream filex("password.txt");
        filex>>passcode;
        cout<<"\n\nPlease enter the password ";
            cin>>password;

            while(passcode!=password){
                cout<<"\nplease enter valid pass word\n press e for exit";
                cin>>password;
                if(password=="e"){
                    return;
                }
            }

        char inp;
            while(test){
        cout<<"\nWhat to do\n1:Manage Available Rooms\n2:Manage Occupied Rooms\n4:Past customer\n \n5:View Profit and bills\n e:exit to main menu";
            cin>>inp;
            if(inp=='1'){
                char inp2;
                cout<<"\nTo do\n1:Add room\n2:See All available Rooms";
                cin>>inp2;
                if(inp2=='1'){
                    menu.addroom();
                }else if(inp2=='2'){
                    menu.print_avilable_room();
                }else  cout<<"\nInvalid Input\n";

            }else if(inp=='2'){
              char inp2;
              cout<<"\nTo do \n1:Empty Room \n2:See all occupied rooms ";
              cin>>inp2;
              if(inp2=='1'){
                  menu.emptyroom();

              }else if(inp2=='2'){
                  menu.seealloccurooms();
              }else cout<<"\nInvalid input\n";
            }else if(inp=='5'){
                char inp2;
                cout<<"\nTo do \n1:View past bills\n2:View profit";
                cin>>inp2;

                if(inp2=='1'){
                    menu.printpastbills();
                }else if(inp2=='2'){
                    menu.displayprofit();
                }else cout<<"\nInvalid input\n";

            }else if(inp=='e'){
                test=0;
            }
    }}
};


#endif //HOTEL_MANAGEMENTSYSTEM_MENU_H
