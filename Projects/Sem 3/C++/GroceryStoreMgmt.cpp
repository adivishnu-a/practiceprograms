#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

class Profit{
        protected:
            double profit;
        public:
            void show()
		    {
		        ifstream x("Profits.txt");
                if(!x)
                    cout<<"\n\t\t\tPROFIT = 0 \n";
                else
                {
                    x>>profit;
                    cout<<"\n\t\t\tTOTAL STARTING PROFIT :  "<<profit<<endl;
                    x.close();
                }
            }
};

class product:public virtual Profit{
    protected:
        int quan;
        char name[20];
        char id[20];
        double percost;
        double persell;
        double cost;
        double sell;
    public:
        void cal();
        void file();
        void get();
};
void product::cal()
{
    cost=percost*quan;
       sell=persell*quan;
       profit=profit+(sell-cost);
}
void product::file()
{
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ofstream f(file);
    f<< "\n\t\t\tProduct Name : "<<name<< "\n\t\t\tProduct ID : "<<id<<"\n\t\t\tCost price of product : " <<percost<<"\n\t\t\tSelling price of product : "<<persell<<"\n\t\t\tQuantity : "<<quan<<"\n\t\t\tTotal cost: "<<cost<<"\n\t\t\tSell : "<<sell<<endl;
    f.close();
    ofstream p("Profits.txt");
    p<<profit;
    p.close();
}
void product::get()
{
    int s;
    cout<<"\n\t\t\tNumber of products to be added : ";
    cin>>s;
    for(int i=0;i<s;i++)
    { 
        cout<<endl;
        cout<<"\t\t\tEnter product name :";
        cin>>name;
        cout<<"\t\t\tEnter product id : ";
        cin>>id;
        cout<<"\t\t\tEnter cost price of product : ";
        cin>>percost;
        cout<<"\t\t\tEnter selling price of product : ";
        cin>>persell; 
        cout<<"\t\t\tTotal products sold quantity : ";
        cin>>quan;
        cal();
        file();
    }
}

class staff:public virtual Profit{
    protected:
        double salary;
        char post[10];
        char empid[10];
        int empquan;
    public:
        void cal();
        void file();
        void getstaff();
};
void staff::cal()
{
    profit=(profit-(salary*empquan)/30);
}
void staff::file()
{
    char file[20];
    strcpy(file,empid);
    strcat(file,".txt");
    ofstream f(file);
    f<< "\n\t\t\tNumber of working employees : "<<empquan<< "\n\t\t\tEmployee Salary : "<<salary<< "\n\t\t\tEmployee Name : "<<post<<"\n\t\t\tEmployee ID : "<<empid<<endl;
    f.close();
    ofstream p("Profits.txt");
    p<<profit;
    p.close();
}
void staff::getstaff()
{
    cout<<"\t\t\tEnter Salary : ";
    cin>>salary;
    cout<<"\t\t\tEnter Number of Employees : ";
    cin>>empquan;
    for(int i=0;i<empquan;i++)
    {
        cout<<endl;
        cout<<"\t\t\tEnter Employee name : ";
        cin>>post;
        cout<<"\t\t\tEnter Employee ID : ";
        cin>>empid;
        cal();
        file();
    }
}

class Records:public staff, public product
{
    public:
        void add();
        void update_item();
        void update_emp();
};
void Records::add()
{
    int ch;
    char name[20];
    while(1)
    {
	    cout<<endl<<"\t\t\t1. Add Products\n\t\t\t2. Add employees\n\t\t\t3. Exit\n";
	    cout<<"\t\t\tEnter choice : ";
	    cin>>ch;
	    if(ch==1)
        {
	        get();
	    }
	    else if(ch==2)
        {
		    getstaff();
	    }
	    else if(ch==3)
		    break;
	    else
		    cout<<"\t\t\tInvaid Option. Try again\n";
    }
}
void Records::update_item()
{
    char id[20];
    char pid[20];
    char c;
    cout<<"\n\t\t\tProduct ID to modify : ";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
        cout<<"\t\t\tProduct ID not found\n";
    }
    else 
    {
        cout<<"\t\t\tProduct found! \n";
        cout<<"\n\t\t\tUpdate product name : ";
        cin>>name;
        cout<<"\t\t\tUpdate Cost Price per product : ";
        cin>>percost;
        cout<<"\t\t\tUpdate Selling Price per product : ";
        cin>>persell;
        cout<<"\t\t\tUpdate total products sold quantity : ";
        cin>>quan;
        cost=percost*quan;
        sell=persell*quan;
        profit=profit +(sell-cost)*365;
        fout<<"\n\t\t\tProduct name : "<<name<< "\n\t\t\tProduct id: "<<id<<"\n\t\t\tCost per product: " <<percost<<"\n\t\t\tSell per product: "<<persell<<"\n\t\t\tQuantity: "<<quan<<"\n\t\t\tTotal cost: "<<cost<<"\n\t\t\tSell: "<<sell;
        fout.close();
    }
}
void Records::update_emp()
{
    char id[20];
    char c;
    cout<<"\n\t\t\tEnter employee ID to modify : ";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {								
        cout<<"\t\t\tEmployee ID not found\n";
    }
    else
    {
        cout<<"\t\t\tUpdate Employee Name : ";
        cin>>post;
        fout<< "\n\t\t\tNumber of working employees: "<<empquan<< "\n\t\t\tEmployee Salary: "<<salary<< "\n\t\t\tEmployee Name :"<<post<<"\n\t\t\tEmployee ID: "<<empid;
        fout.close();
    }
}

void start()
{
    while(1)
    {
        cout<<"\n\t\t\t==============================\n";
        cout<<"\n\t\t\t    WELCOME TO GROCERY MART   \n";
        cout<<"\n\t\t\t==============================\n\n";
        cout<<"\n\t\t\t1. Add Entries\n\n\t\t\t2. Show profit\n\n\t\t\t3. Search Product Details\n\n\t\t\t4. Search Employee Details\n\n\t\t\t5. Modify Product Details\n\n\t\t\t6. Modify Employee Details\n\n\t\t\t7. Exit\n";
        cout<<"\n\n\t\t\tSelect your choice : ";
        int u;
        cin>>u;
        if(u==1)
        {
            Records a;
            a.show();
            a.add();
        }
        else if(u==2)
        {
            Records d;
            d.show();
        }
        else if(u==3)
        {  
            char id[20];
            char c;
            cout<<"\n\t\t\tEnter ID to search : ";
            cin>>id;
            char file[20];
            strcpy(file,id);
            strcat(file,".txt");
            ifstream x(file);
            if(!x)
            {
                cout<<"\n\t\t\tProduct ID not found\n";
            }
            while(x)
            {
                x.get(c);
                cout<<c;
            }
            x.close();
        }
        else if(u==4)
        {
            char eid[20];
            char d;
            cout<<"\n\t\t\tEnter employee ID to search : ";
            cin>>eid;
            char file[20];
            strcpy(file,eid);
            strcat(file,".txt");
            ifstream y(file);
            if(!y)
            {
                cout<<"\n\t\t\tEmployee ID not found. \n";
            }
            while(y)
            {
                y.get(d);
                cout<<d;
            }
            y.close();
        }
        else if(u==5)
        {
            Records u;
            u.update_item();
        }
        else if(u==6)
        {
            Records v;
            v.update_emp();
        }
        else if(u==7)
        {
            break;
        }
        else cout<<"\t\t\tInvalid option. Please select one of the available options\n";
    }
}

int main(){
    int ch;
    while(1)
    {
        system("cls");
        cout<<"\n \t\t\t=========================\n";
        cout<<"\n\t\t\t  WELCOME TO GROCERY MART\n";
        cout<<"\n \t\t\t=========================\n\n";
        cout<<"\n\t\t\t  1. OPEN STORE";
        cout<<"\n\t\t\t  2. CLOSE STORE";
        cout<<"\n\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
            system("cls");
                start();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Choice Invalid, try again\n";
                break;
        }
    }
    return 0;
}