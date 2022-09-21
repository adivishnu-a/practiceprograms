#include<iostream>
using namespace std;

class ITEM
{
    private:
        int number;
        double cost;
    public:
        void putdata();
        void getdata(int,double);
};

void ITEM::putdata(){
    cout << endl << "Item Number: " << number << endl;
    cout << "Item Cost  : " << cost << endl << endl;
}

void ITEM::getdata(int num, double price){
    number = num;
    cost = price;
}

int main()
{
    ITEM x;
    int no;
    double pr;
    cout << "Enter the number of item : ";
    cin >> no;
    cout << "Enter the price of item : ";
    cin >> pr;
    x.getdata(no, pr);
    x.putdata();
    return 0;
}