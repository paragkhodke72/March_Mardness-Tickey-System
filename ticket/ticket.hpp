// ticket headre file as follows
#ifndef ticket_hpp
#define ticket_hpp

#include <iostream> // for the standard stream
#include<string> // string header
#include<time.h> // time library
#include<math.h> // math library
#include <fstream> // for file stream
#include<cstring> //

using namespace std;
// create class names ticket and Declaring as belows
class ticket
{
private: // only for class
    
    char userName[700]; // for user name
    char eventName[700]; // for event name
    char eventTime[700]; // event time
    char artistsName[700];
    char city[700]; // event location
    
    int tid; // ticket ID
    int ticketBooked; // no of tickets booked in events
    int price;
    int availability; // no of availiable seats for events
    int row,seatNo,section; // variables for row ,seatno and sections
    
public:
    ticket (); // constructor with no arguments
    ticket ( int Id,int ro,int fare ); // constructor with arguments
   
    void read(); // to read
    void show(); // to show
    void print() const; // to print for printInventory
    void display  (); // to display
    void sellTicket(char uname[], ticket tb, int number); // pass arguments to sell ticket functions
    void printTicket(char userName[]); // print to console
    
    // getter as follows
    int   getid()             {   return tid;           }
    char* geteventName()      {   return eventName;     }
    int   getMax()            {   return availability;  } // return avaliability
    int   getprice()          {   return price;         } // return price
    
    bool equal (const ticket objT2) const;
    
};

#endif /* ticket_hpp */
