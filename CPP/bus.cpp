#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

class Bus{
    protected:
        string no[10], drname[10];
        string stops[10][10];
        int nb=0,ns[10];
    public:
        void showdetails()
        {
            system("cls");
            cout<<endl;
            cout<<" ------------------- BUS DETAILS ------------------- "<<endl;
            if(nb==0)
            {
                cout<<"               No Buses Available"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
            }
            else
            {
                for(int i=0;i<nb;i++)
                {
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<" Bus "<<(i+1)<<endl;
                    cout<<" Bus Code    : "<<no[i]<<endl;
                    cout<<" Driver Name : "<<drname[i]<<endl;
                    cout<<" Stops       : "<<endl;
                    for(int j=0;j<ns[i];j++)
                    {
                        cout<<(j+1)<<". "<<stops[i][j]<<endl;
                    }
                    cout<<"-----------------------------------------------------"<<endl;
                }
            }
        }
};

class Admin:public virtual Bus
{
    private:
        string id, pass;
    public:
        void addbus()
        {
            system("cls");
            cout<<endl;
            cout<<" ------------------- ADD BUS ------------------- "<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Enter bus code       : ";cin>>no[nb];
            cout<<"Enter driver name      : ";cin>>drname[nb];
            cout<<"Enter number of stops  : ";cin>>ns[nb];
            for(int j=0;j<ns[nb];j++)
            {
                cout<<"Enter stop"<<(j+1)<<"  : ";cin>>stops[nb][j];
            }
            nb++;
            return;
        }
        void removebus()
        {
            string key;
            int index=-1;
            system("cls");
            showdetails();
            cout<<endl;
            cout<<"Which bus do you want to remove?\nEnter bus number : ";cin>>key;
            for(int i=0;i<nb;i++)
            {
                if(key==no[i])
                {
                    index=i;
                }
            }
            if(index==-1)
            {
                cout<<endl;
                cout<<"BUS NOT FOUND!"<<endl;
                return;
            }
            else
            {
                for(int i=index;i<nb;i++)
                {
                    no[i]=no[i+1];
                    drname[i]=drname[i+1];
                    ns[i]=ns[i+1];
                    for(int j=0;j<ns[i];j++)
                    {
                        stops[i][j]=stops[i+1][j];
                    }
                }
                nb--;
            }
            return;
        }
        void adminmenu()
        {
            system("cls");
            adminlogin:
            cout<<endl;
            cout<<" ------------------- ADMIN MENU ------------------- "<<endl;
            cout<<"----------------------------------------------------"<<endl;
            cout<<"                Login to continue"<<endl;
            cout<<"                Enter your ID   : ";cin>>id;
            cout<<"                Enter password  : ";cin>>pass;
            if(id=="admin" & pass=="admin")
            {
                int ch;
                system("cls");
                cout<<"                 LOGIN SUCCESSFUL!                  "<<endl;
                while(1)
                {
                    cout<<endl;
                    cout<<" ------------------- ADMIN MENU ------------------- "<<endl;
                    cout<<"----------------------------------------------------"<<endl;
                    cout<<"                  1. Add Bus                        "<<endl;
                    cout<<"                  2. Remove Bus                     "<<endl;
                    cout<<"                  3. Show Buses                     "<<endl;
                    cout<<"                  4. Logout                         "<<endl;
                    cout<<"----------------------------------------------------"<<endl;
                    cout<<"             Enter your choice : ";cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            addbus();
                            break;
                        case 2:
                            removebus();
                            break;
                        case 3:
                            showdetails();
                            break;
                        case 4:
                            system("cls");
                            cout<<"LOGGED OUT"<<endl;
                            return;
                            break;
                        default:
                            system("cls");
                            cout<<"Invalid Choice, Try Again!"<<endl;
                    }
                }
            }
            else
            {
                cout<<endl;
                cout<<"Incorrect Credentials"<<endl;
                goto adminlogin;
            }
        }
};

class Student:public virtual Bus
{
    private:
        string id[20], name[20], bus[20], stop[20]; 
        int nstu=-1;
        int stopno[20], busno[20];
    public:
        void book()
        {
            showdetails();
            if(nb!=0)
            {
                nstu++;
                cout<<endl;
                cout<<" ------------------- BOOK BUS ------------------- "<<endl;
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Your Booking Number     : "<<(nstu+1)<<endl;
                cout<<"Enter student ID        : ";cin>>id[nstu];
                cout<<"Enter student name      : ";cin>>name[nstu];
                cout<<"Enter Bus Number        : ";cin>>busno[nstu];
                cout<<"Enter Stop Number       : ";cin>>stopno[nstu];
                bus[nstu]=no[busno[nstu]-1];
                stop[nstu]=stops[busno[nstu]-1][stopno[nstu]-1];
            }
            else
            {
                cout<<"No Buses Available!"<<endl;
            }
        }
        void cancel()
        {
            int cno;
            status();
            cout<<endl;
            cout<<" ------------------- CANCEL BUS ------------------- "<<endl;
            cout<<"----------------------------------------------------"<<endl;
            if(nstu!=-1)
            {
            cout<<"Enter Booking Number to cancel : ";cin>>cno;
                if(cno<=(nstu+1))
                {
                    for(int i=cno-1;i<=nstu;i++)
                    {
                        id[i]=id[i+1];
                        name[i]=name[i+1];
                        bus[i]=bus[i+1];
                        stop[i]=stop[i+1];
                        busno[i]=busno[i+1];
                        stopno[i]=stopno[i+1];
                    }
                    nstu--;
                }
                else
                {
                        cout<<"Invalid Booking Number"<<endl;
                }
            }
            else
            {
                cout<<"No registrations available to cancel"<<endl;
            }
        }
        void status()
        {
            cout<<endl;
            cout<<" ------------------- REGISTRATION STATUS ------------------- "<<endl;
            if(nstu==-1)
            {
                cout<<"          NO REGISTRATIONS"<<endl;
            }
            else
            {
                for(int i=0; i<(nstu+1);i++)
                {
                    cout<<"------------------------------------------------------"<<endl;
                    cout<<"          Booking Number : "<<(i+1)<<endl;
                    cout<<"          Student ID     : "<<id[i]<<endl;
                    cout<<"          Student Name   : "<<name[i]<<endl;
                    cout<<"          Bus Code       : "<<bus[i]<<endl;
                    cout<<"          Bus Stop       : "<<stop[i]<<endl;
                    cout<<"------------------------------------------------------"<<endl;
                }
            }
        }
        void studentmenu()
        {
            int ch;
            while(1)
            {
                cout<<endl;
                cout<<" ------------------- STUDENT MENU ------------------- "<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cout<<"                  1. Book Transport                   "<<endl;
                cout<<"                  2. Cancel Transport                 "<<endl;
                cout<<"                  3. View Status                      "<<endl;
                cout<<"                  4. Exit                             "<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cout<<"             Enter your choice : ";cin>>ch;
                switch(ch)
                {
                    case 1:
                        system("cls");
                        book();
                        break;
                    case 2:
                        system("cls");
                        cancel();
                        break;
                    case 3:
                        system("cls");
                        status();
                        break;
                    case 4:
                        cout<<"EXITED"<<endl;
                        return;
                        break;
                    default:
                        system("cls");
                        cout<<"Invalid Choice, Try Again!"<<endl;
                }
            }
        }
};

class Portal:public Admin, public Student
{
    public:
        void start()
        {
            int ch;
            while(1)
            {
                cout<<endl;
                system("cls");
                cout<<" ------------------- MAIN MENU ------------------- "<<endl;
                cout<<"---------------------------------------------------"<<endl;
                cout<<"               1. Login as Admin                   "<<endl;
                cout<<"               2. Use as Student                   "<<endl;
                cout<<"               3. Exit                             "<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cout<<"             Enter your choice : ";cin>>ch;
                switch(ch)
                {
                    case 1:
                        system("cls");
                        adminmenu();
                        break;
                    case 2:
                        system("cls");
                        studentmenu();
                        break;
                    case 3:
                        cout<<"EXITED"<<endl;
                        return;
                        break;
                    default:
                        system("cls");
                        cout<<"Invalid Choice, Try Again!"<<endl;
                }
            }
        }
};

int main()
{
    Portal p;
    p.start();
    return 0;
}