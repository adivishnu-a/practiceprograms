#include <iostream>
using namespace std;
class Student{
    protected:
        int roll;
    public:
        Student(){
            cout<<endl<<"Enter the Roll Number : ";
            cin>>roll;
        }
        void showroll(){
            cout<<endl<<"Roll number : "<<roll<<endl;
        }
};

class Test:public virtual Student{
    protected:
        int math, phy, chem, eng;
    public:
        Test(){
            cout<<endl;
            cout<<"Enter Maths Marks     : ";cin>>math;
            cout<<"Enter Physics Marks   : ";cin>>phy;
            cout<<"Enter Chemistry Marks : ";cin>>chem;
            cout<<"Enter English Marks   : ";cin>>eng;
        }
        void showmarks(){
            cout<<endl<<"Marks List"<<endl;
            cout<<"Maths     : "<<math<<endl;
            cout<<"Physics   : "<<phy<<endl;
            cout<<"Chemistry : "<<chem<<endl;
            cout<<"English   : "<<eng<<endl;
        }
};

class Sports:public virtual Student{
    protected:
        int volley, foot;
    public:
        Sports(){
            cout<<endl;
            cout<<"Enter Volleyball Score : ";cin>>volley;
            cout<<"Enter Football Score   : ";cin>>foot;
        }
        void showscores(){
            cout<<endl<<"Sports Scores"<<endl;
            cout<<"Volleyball Score : "<<volley<<endl;
            cout<<"Football Score   : "<<foot<<endl;
        }
};

class Result:public Test, public Sports{
    private:
        int total;
        float per;
    public:
        Result(){
            total=math+phy+chem+eng+volley+foot;
            per=total/6.0;
            showroll();
            cout<<"Total score : "<<total<<endl;
            cout<<"Percentage  : "<<per<<endl<<endl;
        }
};

int main()
{
    Result r1;
    return 0;
}