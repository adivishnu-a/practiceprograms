#include <iostream>
using namespace std;

int main() 
{ 
	int processCount, resourceCount, i, j, k;
	cout<<"Enter number of processes: ";
	cin>>processCount;
	cout<<"Enter number of resources: ";
	cin>>resourceCount;
	int alloc[processCount][resourceCount];
	int max[processCount][resourceCount];
	int avail[processCount];
	for(int i=0;i<processCount;i++){
	    for(int j=0;j<resourceCount;j++){
	        cout<<"Enter resource "<<j+1<<" allocation for Process "<<i+1<<": ";
	        cin>>alloc[i][j];
	    }
	    cout<<"\n";
	}
	for(int i=0;i<processCount;i++){
	    for(int j=0;j<resourceCount;j++){
	        cout<<"Enter maximum resource "<<j+1<<" consumed by Process "<<i+1<<": ";
	        cin>>max[i][j];
	    }
	    cout<<"\n";
	}
	for(int i=0;i<resourceCount;i++){
	        cout<<"Enter availability of resource "<<i+1<<" : ";
	        cin>>avail[i];
	    }

	int finish[processCount]={0};
	int safeSequence[processCount], pos = 0; 
	int need[processCount][resourceCount]; 
	
	for (i = 0; i < processCount; i++) { 
		for (j = 0; j < resourceCount; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < processCount; k++) { 
		for (i = 0; i < processCount; i++) { 

			if (finish[i] == 0) {  
				bool flag = true; 
				for (j = 0; j < resourceCount; j++) { 
					if (need[i][j] > avail[j]){  
						flag = false; 
						break; 
					} 
				} 

				if (flag == true) {  
					safeSequence[pos++] = i; 
					for (y = 0; y < resourceCount; y++) 
						avail[y] += alloc[i][y]; 
					finish[i] = 1; 
				} 
			} 
		} 
	} 
    cout<<"\nThe safe Sequence is: \n"; 
	for (i = 0; i < processCount - 1; i++) 
		cout<<" P"<<safeSequence[i]<<"->"; 
	cout<<" P"<<safeSequence[processCount - 1]; 

	return 0;
}