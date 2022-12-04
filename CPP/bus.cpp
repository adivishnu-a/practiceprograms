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
            cout<<"Enter bus code       : ";std::getline(std::cin, no[nb]);
            cout<<"Enter driver name      : ";std::getline(std::cin, drname[nb]);
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
        string id, name, bus, stop; 
        int stopno=-1, busno=-1;
    public:
        void book()
        {
            showdetails();
            if(nb!=0)
            {
            cout<<endl;
            cout<<" ------------------- BOOK BUS ------------------- "<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Enter student ID        : ";cin>>id;
            cout<<"Enter student name      : ";cin>>name;
            cout<<"Enter Bus Number        : ";cin>>busno;
            cout<<"Enter Stop Number       : ";cin>>stopno;
            bus=no[busno-1];
            stop=stops[busno-1][stopno-1];
            }
        }
        void cancel()
        {
            cout<<endl;
            cout<<" ------------------- CANCEL BUS ------------------- "<<endl;
            cout<<"----------------------------------------------------"<<endl;
            id="Not registered";
            name="Not registered";
            busno=-1;
            stopno=-1;
        }
        void status()
        {
            cout<<endl;
            cout<<" ------------------- REGISTRATION STATUS ------------------- "<<endl;
            if(busno==-1)
            {
                cout<<"          NOT REGISTERED"<<endl;
            }
            else
            {
                cout<<"          Student ID    : "<<id<<endl;
                cout<<"          Student Name  : "<<name<<endl;
                cout<<"          Bus Code      : "<<bus<<endl;
                cout<<"          Bus Stop      : "<<stop<<endl;
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
