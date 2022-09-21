#include<iostream>
using namespace std;

class Sample
{
    int n;
    static int obj;
    public:
    Sample()
    {
        n=++obj;
    }
    void getObjNo(void)
    {
        cout<<"Object Number:"<<n<<endl;
    }
    static void showcount(void)
    {
        cout<<"Object Count:"<<obj<<endl;
    }
};

int Sample::obj;

int main()
{
    Sample s1,s2;
    cout<<"Created objects s1, s2"<<endl;
    Sample::showcount();
    Sample s3;
    cout<<"Created objects s3"<<endl;
    Sample::showcount();
    s1.getObjNo();
    s2.getObjNo();
    s3.getObjNo();
    return 0;
}
