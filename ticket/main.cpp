 /*                                         main.cpp
 * Author: Parag khodke
 * Version: Created on april-06 (On X' Code)
 * Copyright © Best practice for programmers based on industry and education
standards.This is for eduction purpose only.
 all rights reserved , use with my express written permission only
 * Descripition: This program is written in c++.
 * we creating ticket system using files.
 * ticket.hpp for header file included
 * create 3 objects and call to default constructor first and with arguments
 * greeting users and show some sample event detals
 * get event information from host USER
 * get user choice and perform booking ticket,dpslay all events
 * all declared functions called as follows and display ASCII image for ticket
 * My Assunptions :- Host has to fill event details first and ask users for further
 */

#include "ticket.hpp" // include header file here

void printInventory (ticket stock[25],int n,ticket &objT ); // function
# define MAX_STOCK 25;

int main (void)
{
    int choice; // user choice for events
    string userName; // get username
    int number=0; // number of ticket users want to book
    fstream F,G; // two file stream objects, G for temp file to stored data while booking
// class object declaration
    
    ticket objT; // initializing using default constructor
    //ticket* obj; // uninialized
    ticket pan(3,7,800);
    ticket stock[25]=
        {// call first constructor
            {1,6,100},
            {2,4,150},
            {4,8,200},
        };
    ticket tb;
    int n=3; // the number of items in stock array
    stock[n++]=pan;
    
    // greetings for user and explain about event details
    cout << "Welcome to 'Wood Stock Event' by Parag B.Khodke \n"<<endl; // greetings<<endl;
    cout <<"Please enter your Name :- " <<endl;
    getline ( cin, userName );
    cout << "\nHello, " <<userName << ",  \n\nPlease Enter your choice for the upcoming Event."<<endl;
    cout<<"Look at the Favourate  SAMPLE EVENT details:::\n" <<endl;
    cout <<"Choie\t\tEvent-Name\t\t\t\tArtists Name\t\t\tLocation" <<endl;
    cout <<"-------------------------------------------------------------------------------"<<endl;
    cout <<"1\t\t\tSaturday-Night\t\t\tDrake.\t\t\t\t\tWednesday Sepcial\n2\t\t\tBest-OF-2019\t\t\tJustin Biber.\t\t\tNew york\n3\t\t\tRockstar \t\t\t\tColdplay.\t\t\t\tLA\n4\t\t\tWomen's special\t\t\tAlan Walkar.\t\t\tBoston\n5\t\t\tQuit." <<endl<<endl;
    
    do
    {   // show menu for users and ask to enter
        cout<<"\nEnter 1 for - Add a New event"<<endl;
        cout<<"Enter 2 for - Search spectific event"<<endl;
        cout<<"Enter 3 for - Display All event details"<<endl;
        cout<<"Enter 4 for - Book a Event ticket  "<<endl;
        cout<<"Enter 5 for - Exit "<<endl;
        
        cout<<"\nEnter your choice \n";
        cin>>choice; // get users choice from above
        cout <<"\n";
        
        int id,flag=0; // id = ticket id and flag to check
        switch(choice)
        {
            case 1:
                F.open("i.txt",ios::app ); // open file in append and binary mode
                objT.read(); // call read() using .object of class_name
                F.write((char*)&objT, sizeof(objT)); // write to file and passing address of obj and size of objects
                F.close();
                cout<<"\nEvent added Successfully ! Thank you !\n "<<endl;
                break;// break loop
                
            case 2:
                // show spectific event detals
                cout<<"Enter the Event id ?? \n";
                cin>>id;
                F.open("i.txt",ios::in | ios::binary);// open file in append and binary mode
                
                if(F.fail())
                    cout<<"Sorry ! No Event records found.. Failed to load. \n"<<endl;
                else
                {
                    cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
                    cout<<"EventId\t"<<" EventName\t"<<"  artists\t\t"<<"  time\t"<<"  Seat-Remaning\t\t"<<"   $\t\t "<<"    seatNo\t\t"<<"   row\t\t"
                    <<"section\t"<<"   Location"<<endl;
                cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
                    while( F.read((char*)&objT ,sizeof(objT)) )// write to file and passing address of obj and size of objects
                    {
                        if(objT.getid() == id) // Event id and user's event id compare
                        {
                            objT.show(); // function called
                            flag=1;
                            cout <<endl;
                            break;// break loop
                        }
                    }
                    if(flag==0) // check default flag here
                        cout<<"\nsorry !! Event not found"<<endl;
                }
                F.close();// file closed
                cout<<endl;
                break; // break loop
                
                
            case 3: // display all event details
                F.open("i.txt",ios::in );
                if( !F ) // checking failed for file
                    cout<<"\nSorry !! No event found !!! . Event failed to load.\n "<<endl;
                else
                {
                    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"E_ID\t"<<"Event_Name"<<"\t\t\t"<<"Artists"<<"\t\t\t"<<"Time"<<"\t\t\t"<<"seats-remaning\t\t" <<"Locations"<<endl;
                    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
                    while(F.read((char*)&objT,sizeof(objT)))// write to file and passing address of obj and size of objects
                        objT.display(); // function called
                }
                F.close();
                break;// break loop
                
            case 4: //  for booking tickets
                char ename[500],uname[500];
                cout<<"\nEnter The event name to be booked \n";
                cin>> ename; // ask for enter a event name
                F.open("i.txt",ios::in | ios::out | ios::binary);// open file in append and input ,output binary mode
                if(F.fail())
                    cout<<"\nopps !! Unable to load file. No event found.  \n"<<endl;
                else
                {
                    while(F.read((char*)&objT ,sizeof(objT)))// write to file and passing address of obj and size of objects
                    {
                        if( strcmp(objT.geteventName(), ename )==0) // string compare using getter and users event name choice
                        {
                        cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
                            cout<<"EventId\t"<<" EventName\t"<<"  artists\t\t"<<"  time\t"<<"  Seat-Remaning\t\t"<<"   $\t\t "<<"    seatNo\t\t"<<"   row\t\t"
                            <<"section\t"<<"   Location"<<endl;
                    cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
                            
                            objT.show();
                            flag=1; // set trur flag here
                            cout<<"\nplease Confirm your name again ? \n";
                            cin>>uname; // get username
                            cout << "how many ticket ??"<<endl;
                            cin >> number; // ask no of tickets
                            //objT.book();
                            objT.sellTicket( uname,  tb,  number) ;
                            
                            G.open("tickets.dat",ios::app | ios::binary); // open file in append and binary mode
                            G.write((char*)&objT,sizeof(tb));// write to file and passing address of obj and size of objects
                            G.close(); // temprory file closes
                            F.write((char*)&objT,sizeof(objT));// write to file and passing address of obj and size of objects
                             break;
                        }
                    }
                    if(flag==0) //if flag false display below line
                        cout<<"\nopops !!  No Event on our records\n"<<endl;
                }
                F.close();
                break;// break loop
        }
        
    }while(choice !=5); // till user enter 5- > continue to this event
    
    printInventory(stock, n, objT);

    cout << "Thank you for choosing woodstock festival event. Bye !!!"<<endl; //ending msg for users
    
}
void printInventory (ticket stock[25], int n, ticket &objT ) // function
{
    cout <<"This is just a Inventory :-  \n" <<endl;
    for (int k=0; k<n; ++k)
    {
        if ( objT.equal(stock [k] )) // check from ticket.cpp file and compare for cheking sale or not
            cout << "Ticket is on  sale now"<<endl;
        else{
            cout <<" " <<endl;
            stock[k].print(); // function called
        }
        cout <<endl;
    }
}

