#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void drawline(int n, char symbol)
{
    for(int i=0; i<n; i++)
    cout << symbol;
    cout << "\n" ;
}

class booking
{
    int roomtype,nroom,cid,cim,ciy,cod,com,coy;
    float no,price;
    char cname[15];

public:
    float getno()
    {
        return no;
    }
    char* getname()
    {
        return cname;
    }
    void getdetails()
    {
        float y;
        cout<<"\nEnter a username for your booking: ";
        cin>>cname;
        cout<<"\nEnter room type(1-4): ";
        cin>>roomtype;
        cout<<"\nEnter no. of rooms: ";
        cin>>nroom;
        if(roomtype==1)
        {
            price=nroom*1999;
        }
        else if(roomtype==2)
        {
            price=nroom*1499;
        }
        else if(roomtype==3)
        {
            price=nroom*1100;
        }
        else if(roomtype==4)
        {
            price=nroom*699;
        }
        cout<<"\nDate of checkin(d->m->y):\n";
        cin>>cid>>cim>>ciy;
        cout<<"\nDate of checkout(d->m->y):\n";
        cin>>cod>>com>>coy;
        cout<<"\nTotal price :"<<price;
        cout<<"\n\nPlease enter a 4 digit numerical password to make your booking secure : ";
        cin>>no;
    }

    void showdetails()
    {
        system("cls");
        cout<<"\n\n   ROOM RATES\n ";
        cout<<"\n\n\t1.Suite Room\t\tRS 1999/-\n\n\t2.Luxury\t\tRS 1499/-\n\n\t3.Business Class\tRS 1100/-\n\n\t4.Deluxe\t\tRS 699/-\n\n ";
        drawline(78,'-');
        cout<<"\n\nCustomer name\t\t\t:";
        cout<<cname;
        cout<<"\n\nRoom type(1-4)\t\t\t:";
        cout<<roomtype;
        cout<<"\n\nno. of rooms\t\t\t:";
        cout<<nroom;
        cout<<"\n\nDate of checkin(d->m->y)\t:";
        cout<<cid<<"-"<<cim<<"-"<<ciy;
        cout<<"\n\nDate of checkout(d->m->y)\t:";
        cout<<cod<<"-"<<com<<"-"<<coy;
        cout<<"\n\nTotal price \t\t\t:"<<price;
        cout<<"\n\n";
    }
    float modifyprice(int n,int d)
    {
       float u;
       if(n==1)
        {
            u=price+200*d;
            price=u;
        }
        else if(n==2)
        {
            u=price+220*d;
            price=u;
        }
        else if(n==3)
        {
            u=price+130*d;
            price=u;
        }
        else if(n==4)
        {
            u=price+500*d;
            price=u;
        }
        else if(n==5)
        {
            u=price+700*d;
            price=u;
        }
        return price;
    }
};

void newbooking()
{
    booking b;
    fstream fout;
    fout.open("records.dat",ios::in|ios::out|ios::binary|ios::app);
    system("cls");
    cout<<"\n\n   ROOM RATES\n ";
    cout<<"\n\n\t1.Super luxury\t\tRS 1999/-\n\n\t2.Luxury\t\tRS 1499/-\n\n\t3.Business Class\tRS 1100/-\n\n\t4.Deluxe\t\tRS 699/-\n\n ";
    drawline(78,'-');
    cout<<" customer details \n";
    b.getdetails();
    fout.write((char*)&b,sizeof(b));
    fout.close();
    system("cls");
    cout<<"\n\n Rooms successfully booked.\n Enjoy your stay\n\n";
    system("pause");
}
void bookingstatus()
{
    system("cls");
    float f;
    int flag=1;
    char u[15],nameb[15];
    booking b;
    fstream fin;
    fin.open("records.dat",ios::in);
    cout<<"\n\n                               LOGIN SCREEN\n";
    cout<<"\n\tenter your username: ";
    cin>>nameb;
    cout<<"\n\tenter your booking password: ";
    cin>>f;
    while(!fin.eof())
    {
        fin.read((char*)&b,sizeof(b));
        if(f==b.getno()&&strcmp(nameb,b.getname())==0)
        {
            cout<<"Booking found!\n\n";
            b.showdetails();
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<"\n\tNo booking found!\n\n";
    }
    cout<"\n\n";
    fin.close();
    system("pause");
}

void addon()
{
    system("cls");
    float f,y;
    int cho,d,flag=1;
    booking b;
    char coname[15];
    fstream fin,fout;
    cout<<"\n\n                               LOGIN SCREEN\n";
    cout<<"\n\tenter your username: ";
    cin>>coname;
    cout<<"\n\tEnter your booking password:";
    cin>>f;
    fin.open("records.dat",ios::in|ios::binary);
    fout.open("temp.dat",ios::out|ios::binary);
    while(!fin.eof())
    {
    fin.read((char*)&b,sizeof(b));
    if(b.getno()==f&&strcmp(coname,b.getname())==0)
    {
    char c[15],nameb[15];
    strcpy(nameb,b.getname());
    system("cls");
    cout<<"\n\tWelcome "<<nameb;
    cout<<"\n                           FACILITIES AVAILABLE\n ";
    cout<<"\n\n\t1.Swimming Pool\t\t\tRS 200/- per day\n";
        cout<<"\n\n\t2.Recreational Center\t\tRS 220/- per day\n";
            cout<<"\n\n\t3.24x7 Internet Access\t\tRS 130/- per day\n";
                cout<<"\n\n\t4.Casino\t\t\tRS 500/- per day\n";
                    cout<<"\n\n\t5.Digital Plaza Entry\t\tRS 700/- per day\n";
    drawline(78,'-');
    cout<<"\n\nEnter your choice:";
    cin>>cho;
    cout<<"\n\nEnter no. of days you want this facility:";
    cin>>d;
    y=b.modifyprice(cho,d);
    fout.write((char*)&b,sizeof(b));
    cout<<"\n\tFacility access granted!\n\n\tYour new booking price:";
    cout<<y<<"\n\n";
    flag=0;
    break;
    }
    else
        fout.write((char*)&b,sizeof(b));
    }
    if(flag==1)
    {
        cout<<"\n\t\tNo record found!\n\n";
    }
    fin.close();
    fout.close();
    remove("records.dat");
    rename("temp.dat","records.dat");
    system("pause");
}

void about()
{
    system("cls");
    cout<<"\n\n                           HOTEL MANAGEMENT SOFTWARE";
    cout<<"\n\n                                   ABOUT\n\n";
    cout<<"\t1.Simple and Secure(password protected)\n\n\t2.Studded with essential features of an OOP language\n\n\t3.Convenient use\n\n\t4.A real world application\n\n";
    cout<<"\t5.Easy fabrication and maintenance\n\n";
    system("pause");
}

void intro()
{
    system("cls");
    cout<<"\n\n                       HOTEL MANAGEMENT SOFTWARE(C.S. Project)                   ";
    drawline(78,'-');
    cout<<"\n\n\n\nPrepared by: Akhil Kumar Donka(XII-A)             Guided by: Meena Gupta mam";
    cout<<"\n           : Avinash Shrivastav(XII-A)\n\n\nPRESS ANY KEY TO CONTINUE";
    cin.get();
    system("cls");
}
int main()
{
    int ch;
    intro();
    do
    {
    system("cls");
    cout<<"\n\n                                 MAIN SCREEN\n ";
    drawline(78,'-');
    cout<<"\n\n\t1.New booking\n\n\t2.Booking status\n\n\t3.Add on facilities\n\n\t4.About software\n\n\t5.Exit\n\n";
    cout<<"\nEnter choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        newbooking();
        break;

    case 2:
        bookingstatus();
        break;

    case 3:
        addon();
        break;

    case 4:
        about();
        break;

    case 5:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\t\t\tThankyou for using this software\n\n\n\n\n\n";
        break;
    }
    }
    while(ch!=5);
return 0;
}
