#include <iostream>
using namespace std;
class Sample
{
	private:
		int x, y;
	public:
		Sample()
		{
			cout<<"Enter value of x : ";
            cin>>x;
			cout<<"Enter value of y : ";
            cin>>y;
		}
		void operator -()
		{
			x = -x;
            y = -y;
		}
		void display()
		{
			cout<<"x = "<<x<<", y = "<<y<<endl;
		}
};

int main()
{
	Sample s;
    cout<<"Before using operator: ";
    s.display();
	-s;
    cout<<"After using operator: ";
	s.display();
	return 0;
}