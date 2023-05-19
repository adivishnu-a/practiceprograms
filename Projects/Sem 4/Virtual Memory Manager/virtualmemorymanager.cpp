#include<iostream>
#include<string.h>
#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;

const int VirtualMemorySize=256;
const int PageSize=256;
const int MemoryManagerSize=256;
const int TLBSize=16;

void print(float var)
{
    printf("%.2f", var);
	printf(" %%");
}

int disp(int var){
	if(var<10)
		cout << "0000" << var;
	else if (var<100)
		cout << "000" << var;
	else if (var<1000)
		cout << "00" << var;	
	else if (var<10000)
		cout << "0" << var;
	else
		cout << var;
}

int main(int argc, char* argv[])
{
	FILE *fp;
	fp=fopen("inputs.txt","r");
	if(fp==NULL)
	{
		cout << "File Not Found\n";
		return 0;
	}

	ifstream memoryFile("physical_memory.bin", ios::binary);
        if (!memoryFile) {
            cout << "physical memory file not found." << endl;
            return 1;
        }

	char *value=NULL;
	char data;
	size_t len=0;
	size_t read;
    int tlb[TLBSize][2];
	int pagetable[PageSize];
	int pos=0, phyAddress=0,frame,logAddress;
	long long page_no,offset,page_table,totalhits=0,fault=0,pages=0;

	memset(tlb,-1,TLBSize*2*sizeof(tlb[0][0]));
	memset(pagetable,-1,sizeof(pagetable));
	
	int mask=255,mask1=62580,i,hit;
	
	while((read=getline(&value,&len,fp))!=-1)
	{
		pages++;
		
		page_no=atoi(value);
		page_no=page_no>>8;
		page_no=page_no & mask;
		
		offset=atoi(value);
		offset=offset & mask;
		
		logAddress=atoi(value);
		
		frame=0, phyAddress=0;
		
		hit=0;			
		for(i=0;i<TLBSize;i++)
		{
			if(tlb[i][0]==page_no)
			{
				hit=1;
				totalhits++;
				frame=tlb[i][1];
				break;
			}
		}
        
		if(hit!=1)
		{
			
			int f=0;
			for(i=0;i<PageSize;i++)
			{
				if(pagetable[i]==page_no)
				{
					frame=i;
					fault++;
					break;
				}
				if(pagetable[i]==-1)
				{
					f=1;
					
					break;
				}
			}
			if(f==1)
			{
				pagetable[i]=page_no;
				frame=i;
			}
			
			tlb[pos][0]=page_no;
			tlb[pos][1]=i;
			pos++;
			pos=pos%15;		
		}

		cout << "Virtual Address : "; disp(logAddress);
		
		phyAddress=frame*PageSize + offset;
		cout << "\t---\tPhysical Address : "; disp(phyAddress);

        memoryFile.seekg(phyAddress, ios::beg);
        memoryFile.read(&data, sizeof(data));

		cout << "\t---\tValue : " << (int)data;

        if(hit==1)
			cout << "  -->  TLB HIT";
        cout << "\n";
        
	}
	double TLBHitRate=(double)totalhits/pages*100;
	double pageTableHitRate=(double)(pages-totalhits)/pages*100;
	cout << "\nTLB Hit Rate : "; print(TLBHitRate);
	cout << "\nTLB Miss Rate : "; print(100-TLBHitRate);
	cout << "\nPage Table Hit Rate : "; print(pageTableHitRate);
	cout << "\nPage Table Miss Rate : "; print(100-pageTableHitRate);
	cout<<endl<<endl;
    fclose(fp);
}