#include <iostream>
using namespace std;

class alpha 
{ 
   	public: 
   	alpha() 
   	{ 
       cout<<"Constructor of alpha class is called"<<endl; 
   	} 
}; 
class beta  
{ 
   	public: 
  	beta() 
   	{ 
       cout<<"Constructor of beta class is called"<<endl; 
   	} 
}; 
class gamma : public alpha, public beta  
{ 
   	public: 
   	gamma() 
   	{ 
       cout<<"Constructor of gamma class is called"<<endl; 
   	} 
}; 
int main() 
{ 
   	gamma g; 
   	return 0; 
}