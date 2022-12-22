#include<iostream>
using namespace std;
 
class Manager
{
  char name[30];
  int age,salary;
  public:
  void getdata();
  void putdata();
};

void Manager::getdata()
{
  cout << "Enter Name : ";
  cin >> name;
  cout << "Enter Age : ";
  cin >> age;
  cout << "Enter Salary : ";
  cin >> salary;
}

void Manager::putdata()
{
  cout << "Name: "<<name<< endl;
  cout << "Age: "<<age<< endl;
  cout << "Salary: "<<salary<< endl<<endl;
  cout << endl;
}

int main()
{
  Manager man[30];
  int n, i;
  cout << "Enter Number of Managers: ";
  cin >> n;

  for(i = 0; i < n; i++)
  {
    cout<<endl<<"Enter Details of Manager "<<(i+1)<<":"<<endl;
    man[i].getdata();
  }

  cout <<endl<< "Manager Data: " << endl<<endl;

  for(i = 0; i < n; i++)
  {
    cout<<"Manager "<<i+1<<":"<<endl;
    man[i].putdata();
  }
}