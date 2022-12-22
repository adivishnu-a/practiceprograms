/*
//auto
#include <iostream>
using namespace std;

void autoClass()
{
    auto a = 149;
    auto b = 69;
    auto c = "Object Oriented Programming with C++";
    auto d = "CSE - C";
    cout << a << " \n";
    cout << b << " \n";
    cout << c << " \n";
    cout << d << " \n";
}

int main()
{
    autoClass();
    return 0;
}
*/

/*
//register
#include <iostream>
using namespace std;

void registerClass()
{
    register char b = 'C';
    cout << "The value of 'b'"<< " declared in register as: " << b;
}

int main()
{
    registerClass();
    return 0;
}
*/

/*
//static
#include <iostream>
using namespace std;

int staticClass()
{
    cout << "For static variables: ";
    static int count = 0;
    count++;
    return count;
}

int nonstaticClass()
{
   cout << "For Non-Static variables: ";
   int count = 0;
   count++;
   return count;
}
int main()
{
    cout << staticClass() << "\n";
    cout << staticClass() << "\n";
    cout << nonstaticClass() << "\n";
    cout << nonstaticClass() << "\n";
    return 0;
}
*/


/*
//extern
#include <iostream>
using namespace std;

int x;
void externClass()
{
	extern int x;
	cout << "Value of the variable 'x' " << "declared  as extern: " << x << "\n";
	x = 2;
	cout<< "Modified value of the variable 'x'" << " declared as extern: " << x;
}

int main()
{
	externClass();
	return 0;
}
*/



//mutable
#include <iostream>
using namespace std;

class Demo 
{
    public:
        int a;
        mutable int b;
        Demo() 
        {
            a = 10;
            b = 20;
        }
};

int main()
{
    const Demo d1;
    d1.b = 30;
    cout << "Value of b = " << d1.b << endl;
    //d1.a = 8;
    cout << "Value of a = " << d1.a << endl;
    return 0;
}
