#include<iostream>
using namespace std;

class Account
{
    private:
        string name, type;
        int accno;
        double balance=0;
    public:
        void assign(string, int, string, double);
        void deposit(double);
        void withdraw(double);
        void display();
};

void Account::assign(string uname, int uno, string utype, double ubal)
{
    name = uname;
    accno = uno;
    type = utype;
    balance = ubal;
}

void Account::deposit(double amt)
{
    balance = balance + amt;
    cout << endl << "Rs. " << amt << " deposited to your account" << endl;
    cout << "Updated account balance : Rs." << balance << endl << endl; 
}

void Account::withdraw(double amt)
{
    if(balance == 0 || amt > balance)
    {
        cout << "Withdrawal not possible";
        return;
    }
    balance = balance - amt;
    cout << endl << "Rs. " << amt << " withdrawn from your account" << endl;
    cout << "Updated account balance : Rs. " << balance << endl << endl;
}

void Account::display()
{
    cout << endl << "--------------------------------------";
    cout << endl << "Account User Name : " << name << endl;
    cout << "Account Number : " << accno << endl;
    cout << "Type of the account : " << type << endl;
    cout << "Account Balance : " << balance << endl;
    cout << "--------------------------------------" << endl << endl;
}

int main()
{
    Account user;
    string uname, utype;
    int uno, ch;
    double amt;
    cout << "Enter the user name : ";
    cin >> uname;
    cout << "Enter the user account number : ";
    cin >> uno;
    cout << "Enter the account type (current/savings) : ";
    cin >> utype;
    cout << "Enter the initial account balance : ";
    cin >> amt;
    user.assign(uname, uno, utype, amt);
    while(1)
    {
        cout << endl << "1. Deposit" << endl << "2. Withdraw" << endl;
        cout << "3. Display" << endl << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        if(ch == 1)
        {
            cout << "Enter the amount to be deposited : ";
            cin >> amt;
            user.deposit(amt);
        }
        else if(ch == 2)
        {
            cout << "Enter the amount to be withdrawn : ";
            cin >> amt;
            user.withdraw(amt);
        }
        else if(ch == 3)
        {
            user.display();
        }
        else if(ch == 4)
        {
            cout << endl << "PROGRAM EXITED";
            break;
        }
        else
        {
            cout << "Invalid choice";
        }
    }
    return 0;
}