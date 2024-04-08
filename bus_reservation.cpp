#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class a
{
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], ticket[10], seat[8][8][10];

public:
    void update();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} bus[10];
void vline(char ch)
{
    for (int i = 80; i > 0; i--)
        cout << ch;
}
void a::update()
{
    cout << "\nEnter bus no: ";
    cin >> bus[p].busn;
    cout << "\nEnter Driver's name: ";
    cin >> bus[p].driver;
    cout << "\nArrival time: ";
    cin >> bus[p].arrival;
    cout << "\nDeparture: ";
    cin >> bus[p].depart;
    cout << "\nFrom:\t";
    cin >> bus[p].from;
    cout << "\nTo:\t";
    cin >> bus[p].to;
    cout << "\nEnter the price of ticket:";
    cin >> bus[p].ticket;
    bus[p].empty();
    p++;
}
void a::allotment()
{
    int seat;
    char number[5];
top:
    cout << "\nBus no: ";
    cin >> number;
    int n;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    while (n <= p)
    {
        cout << "\nSeat Number: ";
        cin >> seat;
        if (seat > 32)
        {
            cout << "\nThere are only 32 seats available in this bus.";
        }
        else
        {
            if (strcmp(bus[n].seat[(seat - 1) / 4][((seat - 1) % 4)], "Empty") == 0)
            {
                cout << "Enter passanger's name: ";
                cin >> bus[n].seat[(seat - 1) / 4][((seat - 1) % 4)];
                break;
            }
            else
                cout << "The seat no. is already reserved.\n";
        }
    }
    if (n > p)
    {
        cout << "Enter correct bus no.\n";
        goto top;
    }
}
void a::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}
void a::show()
{
    int n;
    char number[5];
    cout << "\nEnter bus no: ";
    cin >> number;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    while (n <= p)
    {
        vline('*');
        cout << "\nBus no: \t" << bus[n].busn
             << "\nDriver: \t" << bus[n].driver << "\t\tArrival time: \t"
             << bus[n].arrival << "\tDeparture time:" << bus[n].depart
             << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t" << bus[n].to << "\tTicket:\t" << bus[n].ticket << "\n";
        vline('*');
        bus[0].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                    cout << "\nThe seat no " << (a - 1) << " is reserved for " << bus[n].seat[i][j]<<endl;
            }
        }
        break;
    }
    if (n > p)
        cout << "Enter correct bus no: ";
}
void a::position(int l)
{
    int s = 0;
    p = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " seats empty in Bus No: " << bus[l].busn<<"\n";
}
void a::avail()
{
    for (int n = 0; n < 10; n++)
    {
        vline('*');
        cout << "\nBus no: \t" << bus[n].busn << "\nDriver: \t" << bus[n].driver
             << "\t\tArrival time: \t" << bus[n].arrival << "\tDeparture Time:\t"
             << bus[n].depart << "\nFrom: \t\t" << bus[n].from << "\t\tTo:\t\t"
             << bus[n].to << "\tTicket: \t" << bus[n].ticket << "\n";
        vline('*');
    }
}


int main()
{
    int w, ch;
    cout << "/************ Bus Reservation **************/" << endl;
    do{
    cout << "\n Enter choice: \n 1-Admin\n 2-User\n 3-Exit\n";
    cin >> ch;
    if(ch==1){
         cout << "\nWelcome To Admin section!!!\n";
        cout << "\n";
        cout << "\t1.Update new bus in depot\n\t"
             << "2.Buses Available\n\t"
             << "3.Show bus status\n\t";
        cout << "\n\tEnter your choice:-> ";
        cin >> w;
        switch (w)
        {
        case 1:
            bus[p].update();
            break;
       
        case 2:
            bus[0].avail();
            break;
        case 3:
            bus[0].show();
            break;
        default:cout<<"Enter correct number\n";
        }
    }
    else if(ch==2){
        cout<<"WELCOME TO USER SECTION!!!\n\n";
     cout << "\t1.Buses Available\n\t"
             <<"2.Reservation\n\t"
             << "3.Show \n\t";
             cout<<"\n";
        cout << "\n\tEnter your choice:-> ";
        cin >> w;
        switch (w)
        {
         case 1:
            bus[0].avail();
            break;
        case 2:
            bus[p].allotment();
            break;
       
        case 3:
            bus[0].show();
            break;
        default: cout<<"Enter correct number\n";
        }
    }
    else if(ch==3){
        cout<<"Thank you\n";
    }
    else{
        cout<<"Please enter correct number\n";
    }
    }while(ch!=3);
   
    return 0;
}
