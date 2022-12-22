#include<iostream>
using namespace std;

class items
{
    int code[100];
    int price[100];
    int c=0;
    public:
        void getitem()
        {
            cout<<"Enter Item Code: ";
            cin>>code[c];
            cout<<"Enter Item Cost: ";
            cin>>price[c];
            c++;
        }
        void removeItem(void)
        {
            int n;
            cout<<"Enter item Code: ";
            cin>>n;
            for(int i=0;i<c;i++)
                if(code[i] == n)
                    price[i] = 0;
        }
        void displaySum(void)
        {
            float sum = 0;
            for(int i=0;i<c;i++)
                sum = sum + price[i];
            cout<<"\nTotal value: "<<sum<<endl<<endl;
        }
};

int main()
{
    items order;
    int ch;
    do
    {
        cout<<"\n1. Add an item"<<endl;
        cout<<"2. Delete an item"<<endl;
        cout<<"3. Display total value"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"What is your Options: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
                order.getitem();
                break;
            case 2:
                order.removeItem();
                break;
            case 3:
                order.displaySum();
                break;
            case 4:
                cout<<"Program Exited"<<endl<<endl;
                exit(0);
            default :
                cout<<"Invalid choice, try again"<<endl<<endl;
        }
    }while(ch != 4);
    return 0;
}
