#include <iostream>
#include "Menu.h"

using namespace std;

#include "Room.h"
#include "Customer.h"
#include "employee.h"
#include "Adminmenu.h"
#include "Checkin.h"
#include "Checkout.h"


Menu *Menu::instance= 0;
int Room::idsetter=0;
int Customer::idsetter=0;
int Employee::idsetter=0;
int main(){
    Menu *program=Menu::getinstance();
    char inp;
    while(1){
    cout<<"\nTo do\n1:Check in \n2:Check out\na:Admin menu\ne:Exit";
    cin>>inp;

    if(inp=='1'){
        program->checkin();
    }else if(inp=='2'){
        program->checkout();
    }else if(inp=='a'){
        program->Adminmenu();
    }else if(inp=='e'){


        return 0;
    }

    }