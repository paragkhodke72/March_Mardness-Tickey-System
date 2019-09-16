/* create default constructor
 create construcor with arguments
 read function to read data from HOST of the event (create event details)
 show to print spectifi events
 displayto print  all the event details
 sell ticket is used to check weather ticket available or not
 printTicket is used to print the ticket is ASCII formatted
 bool is check for print inventory
 
 */

#include "ticket.hpp" // include ticket header files

ticket:: ticket() // default constructor
{
// default constructor with no arguments
    this -> tid=0;
// proper us of THIS operator
// to refer to implied parameters
    this-> availability=25;
    this -> ticketBooked=0;
            price=0;
            section =0;
            strcpy ( city, ""); // copy event Location entered  by host into 'city'
            strcpy ( userName   , "");// copy user name by user into username
            strcpy ( eventName  , "");// copy event name entered  by host
            strcpy ( eventTime  , "");// copy event time entered  by host
            strcpy ( artistsName, "");// copy artists name entered  by host into 'artistsName'
}
//-----------------------------------------------------------------------------------

ticket :: ticket(int Id,int ro, int fare)// constructor with arguments
{
    tid=Id;
    row = ro;
    price = fare;
}
//-----------------------------------------------------------------------------------

void ticket::read() // get event details by admin
{
//reading directly into the objects
//no need for temp.variables
    cout<<"Enter Event id:- "; // event id
    cin>>tid;
    cout<<"Enter event Name:- "; // event  name
    cin >> eventName  ;
    cout << "Artists name ?? "<<endl;// event  artist name
    cin >> artistsName;
    cout<<"Enter time of event(use AM/PM):- " ;// event timing
    cin >> eventTime ;
    cout<<"Enter price for this in $ :- ";// event  price
    cin>>price;
    cout << "Enter row for this:-"<<endl;// row number
    cin >> row;
    cout << "enter Seat number:- "<<endl;// seat number
    cin >> seatNo;
    cout << "Enter section for that ?:- "<<endl;// in which section
    cin >> section;
    cout << "Enter Location for event ?:- "<<endl;// event location
    cin >> city;
    
}

//-----------------------------------------------------------------------------------
//******************** print all details for events
void ticket::show()
{
    cout<<tid<<"\t      "<<eventName <<"\t\t"<<artistsName<<"\t\t\t"<<eventTime<<"\t\t\t"<<availability-ticketBooked<<"\t\t\t\t"<<price <<"\t\t\t\t"<<seatNo <<"\t\t\t"<< row <<"\t\t\t"<<section<<"\t\t\t"<< city<<  endl;
}

//---------------------------------------------------------------------------------
//*************************// display Tid,name,time,seats remaning and city
void ticket::display()
{
    cout<<tid<<"\t\t"<<eventName<<"\t\t\t\t"<<artistsName<<"\t\t\t\t"<<eventTime<<"\t\t\t\t"<<availability-ticketBooked<<"\t\t\t\t"<< city<<endl;
    //exit(1);
}

//----------------------------------------------------------------------------------
 // Generate function for  username and copy class objects here
void ticket::sellTicket(char uname[], ticket tb, int number)
{
    ticket objT; // create object
    objT=tb; // object copie
    int temp=0; // temparory number for remaning seats
    temp = availability-ticketBooked; // copied remaning seats into temp variables for further checking
    if (number < temp) // checking if remaning ticket to users number of ticket, if not equal -> sold
    {
        cout << "Ticked sold"<<endl;
        temp = temp-1 ;  // decrement temp
        printTicket(userName); // function call
    }
    else
        cout <<"Sorry "<<uname <<"  , Insufficient availiable tickets , you can try again !!! " <<endl;
}
//------------------------------------------------------------------------------------
//**************** print ticket using ASCII

void ticket::printTicket( char uname[]) // get username and print ticket to console
{
    cout << "\nPickup your following ticket :-  "<<endl;
    //time_t t = time(NULL);
    //tm* timePtr = localtime(&t);
    cout << "\t|***************************************************************************************|" << endl;
    cout << "\t       @ WOOD STOCK MUSIC and ARTS FAIR @                                               |"<< endl;
    cout << "\t|---------------------------------------------------------------------------------------|" << endl;
   // cout << "\t|"<<"Minutes= " <<timePtr->tm_min<<"  Hours= "<<timePtr->tm_hour<<", "<<"Date:- "
     //          <<timePtr->tm_mday <<"\t\t\tmonth= " << timePtr->tm_mday<< "\t\t\t\tyear = " << timePtr->tm_year + 1900 <<"\t|" << endl;
    cout<<"\t|\tID:-"<<tid <<"\t\t\t\tEvent-Name:-" << eventName <<"\t\tBy:-"<<artistsName<<"\t\tTime:- "<<eventTime<<"  \t$ " << price <<"\t\t\t      |"<<endl;
    cout <<"\t|\tSeatNo:- "<<seatNo <<"\t\t\tRow:-"<< row <<"\t\t\t\t\tSection:-"<<section << "\t\tAddress:-"<< city <<"\t\t\t    |"<<endl;
    cout << "\t|                                                                                       |" << endl;
    cout << "\t|                                                                                       |" << endl;
    cout << "\t|                                                                                       |" << endl;
    cout << "\t|Good For One Admission only !                                                          |" << endl;
    cout << "\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "\t|NO REFUND                       Thanks for Choosing !!!\t\t\tBe Safe!            |" << endl;
    cout << "\t|***************************************************************************************|" << endl;cout << endl << endl;
    
}
//----------------------------------------------------------------------------------------

//********** print for printInventory from main
void ticket::print() const
{
 
    cout <<"Ticket_id:- " << tid << "    Row-No.:- "<<row <<"    Price:-$ "<< price<<endl;
}
// ********* to check the following conditions
bool ticket :: equal (const ticket objT2) const
{
    return( this -> tid == objT2.tid ) &&
            (row == objT2.row)&&
            (price == objT2.price);
}
