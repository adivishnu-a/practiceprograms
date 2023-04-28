#include <iostream>
using namespace std;

struct Process
{
    int pid;
    int type;
    int burestime;
    int prt;
    int ct;
    int tatime;
    int waittime;
    int remtime;
    int restime;
};

struct fcfs{
    int pid;
    int burestime;
    int ct;
    int tatime;
    int waittime;
    int remtime;
    int restime;
};

struct rr2{
    int pid;
    int burestime;
    int ct;
    int tatime;
    int waittime;
    int remtime;
    int restime;
};

struct rr4{
    int pid;
    int burestime;
    int ct;
    int tatime;
    int waittime;
    int remtime;
    int restime;
};

struct sjf{
    int pid;
    int burestime;
    int ct;
    int tatime;
    int waittime;
    int remtime;
    int restime;
};

struct prt{
    int pid;
    int burestime;
    int prt;
    int ct;
    int tatime;
    int waittime;
    int remtime;
    int restime;
};

int calcfcfs(fcfs f[], int f_count,int time){
    for (int i = 0; i < f_count; i++)
    {
        f[i].ct=0;
        f[i].tatime=0;
        f[i].waittime=0;
        f[i].restime=0;
        f[i].ct=time+f[i].burestime;
        time=f[i].ct;
        f[i].tatime=f[i].ct;
        f[i].waittime=f[i].tatime-f[i].burestime;
        f[i].restime=f[i].waittime;
    }
   
    for (int i = 0; i < f_count; i++)
    {
        cout<<f[i].pid<<"\t"<<f[i].burestime<<"\t\t"<<f[i].ct<<"\t\t"<<f[i].tatime<<"\t\t\t"<<f[i].waittime<<"\t\t"<<endl;
    }
    return time;
}

int calcr2(rr2 r2[], int r2_count,int time){
    for (int i = 0; i < r2_count; i++)
    {
        r2[i].ct=0;
        r2[i].tatime=0;
        r2[i].waittime=0;
        r2[i].restime=0;
        r2[i].remtime=r2[i].burestime;
    }
    int flag=0;
    while (flag==0)
    {
        flag=1;
        for (int i = 0; i < r2_count; i++)
        {
            if (r2[i].remtime>2)
            {
                time+=2;
                r2[i].remtime-=2;
                flag=0;
            }
            else if (r2[i].remtime>0)
            {
                time+=r2[i].remtime;
                r2[i].remtime=0;
                r2[i].ct=time;
                r2[i].tatime=r2[i].ct;
                r2[i].waittime=r2[i].tatime-r2[i].burestime;
                r2[i].restime=r2[i].waittime;
            }
        }
    }
    
    
    for (int i = 0; i < r2_count; i++)
    {
        cout<<r2[i].pid<<"\t"<<r2[i].burestime<<"\t\t"<<r2[i].ct<<"\t\t"<<r2[i].tatime<<"\t\t\t"<<r2[i].waittime<<"\t\t"<<endl;
    }
    return time;
}

int calcr4(rr4 r4[], int r4_count, int time){
    for (int i = 0; i < r4_count; i++)
    {
        r4[i].ct=0;
        r4[i].tatime=0;
        r4[i].waittime=0;
        r4[i].restime=0;
        r4[i].remtime=r4[i].burestime;
    }
    int flag=0;
    while (flag==0)
    {
        flag=1;
        for (int i = 0; i < r4_count; i++)
        {
            if (r4[i].remtime>4)
            {
                time+=4;
                r4[i].remtime-=4;
                flag=0;
            }
            else if (r4[i].remtime>0)
            {
                time+=r4[i].remtime;
                r4[i].remtime=0;
                r4[i].ct=time;
                r4[i].tatime=r4[i].ct;
                r4[i].waittime=r4[i].tatime-r4[i].burestime;
                r4[i].restime=r4[i].waittime;
            }
        }
    }
    
    
    for (int i = 0; i < r4_count; i++)
    {
        cout<<r4[i].pid<<"\t"<<r4[i].burestime<<"\t\t"<<r4[i].ct<<"\t\t"<<r4[i].tatime<<"\t\t\t"<<r4[i].waittime<<"\t\t"<<endl;
    }
    return time;
}

int calcsjf(sjf s[], int s_count, int time){
    for (int i = 0; i < s_count; i++)
    {
        s[i].ct=0;
        s[i].tatime=0;
        s[i].waittime=0;
        s[i].restime=0;
        s[i].remtime=s[i].burestime;
    }
    int flag=0;
    while (flag==0)
    {
        flag=1;
        for (int i = 0; i < s_count; i++)
        {
            if (s[i].remtime>0)
            {
                time+=s[i].remtime;
                s[i].remtime=0;
                s[i].ct=time;
                s[i].tatime=s[i].ct;
                s[i].waittime=s[i].tatime-s[i].burestime;
                s[i].restime=s[i].waittime;
            }
        }
    }
    
    for (int i = 0; i < s_count; i++)
    {
        cout<<s[i].pid<<"\t"<<s[i].burestime<<"\t\t"<<s[i].ct<<"\t\t"<<s[i].tatime<<"\t\t\t"<<s[i].waittime<<"\t\t"<<endl;
    }
    return time;
}

int calcprt(prt p[], int p_count,int time){
    for (int i = 0; i < p_count; i++)
    {
        p[i].ct=0;
        p[i].tatime=0;
        p[i].waittime=0;
        p[i].restime=0;
        p[i].remtime=p[i].burestime;
    }
    int flag=0;
    while (flag==0)
    {
        flag=1;
        for (int i = 0; i < p_count; i++)
        {
            if (p[i].remtime>0)
            {
                time+=p[i].remtime;
                p[i].remtime=0;
                p[i].ct=time;
                p[i].tatime=p[i].ct;
                p[i].waittime=p[i].tatime-p[i].burestime;
                p[i].restime=p[i].waittime;
            }
        }
    }
    
    for (int i = 0; i < p_count; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].burestime<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tatime<<"\t\t\t"<<p[i].waittime<<"\t\t"<<endl;
    }
    return time;
}

int multiqueue(fcfs f[], rr2 r2[], rr4 r4[], sjf s[], prt p[], int f_count, int r2_count, int r4_count, int s_count, int p_count, int n){
    int time=0;
    cout<<endl;
    cout<<"multiqueue"<<endl;
    cout<<"PID\tBurestime Time\tCompletion Time\tTurn Around Time\tWait Time\t"<<endl;
    time=calcfcfs(f,f_count,time);
    time=calcr2(r2,r2_count,time);
    time=calcr4(r4,r4_count,time);
    time=calcsjf(s,s_count,time);
    time=calcprt(p,p_count,time);
    return 0;
}

int main()
{
    int n;
    cout<<"Enter total number of processes: ";    
    cin>>n;
    Process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        cout<<"Enter the process ID: ";
        cin>>p[i].pid;
        cout<<"Enter the type of process: ";
        cin>>p[i].type;
        switch (p[i].type)
        {
        case 1:
            cout<<"Enter the burestime time: ";
            cin>>p[i].burestime;
            break;
        case 2:
            cout<<"Enter the burestime time: ";
            cin>>p[i].burestime;
            break;
        case 3:
            cout<<"Enter the burestime time: ";
            cin>>p[i].burestime;
            break;
        case 4:
            cout<<"Enter the burestime time: ";
            cin>>p[i].burestime;
            break;
        case 5:
            cout<<"Enter the burestime time: ";
            cin>>p[i].burestime;
            cout<<"Enter the prt: ";    
            cin>>p[i].prt;
            break;
        default:
            break;
        }
    }
   
    int f_count=0;
    int r2_count=0;
    int r4_count=0;
    int s_count=0;
    int p_count=0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].type==1)
        {
            f_count++;
        }
        else if (p[i].type==2)
        {
            r2_count++;
        }
        else if (p[i].type==3)
        {
            r4_count++;
        }
        else if (p[i].type==4)
        {
            s_count++;
        }
        else if (p[i].type==5)
        {
            p_count++;
        }
    }

    fcfs f[f_count];
    rr2 r2[r2_count];
    rr4 r4[r4_count];
    sjf s[s_count];
    prt pr[p_count];

    int n1=0, n2=0, n3=0, n4=0, n5=0;
    
    for (int i = 0; i < n; i++)
    {
        if(p[i].type==1){
            f[n1].pid=p[i].pid;
            f[n1].burestime= p[i].burestime;
            n1++;
  
        }
        else if (p[i].type==2)
        {
            r2[n2].pid=p[i].pid;
            r2[n2].burestime=p[i].burestime;
            n2++;
 
        }
        else if (p[i].type==3)
        {
            r4[n3].pid=p[i].pid;
            r4[n3].burestime=p[i].burestime;
            n3++;
      
        }
        else if (p[i].type==4)
        {
            s[n4].pid=p[i].pid;
            s[n4].burestime=p[i].burestime;
            n4++;
           
        }
        else if (p[i].type==5)
        {
            pr[n5].pid=p[i].pid;
            pr[n5].burestime=p[i].burestime;
            pr[n5].prt=p[i].prt;
            n5++;

        }  
    }
   
    multiqueue(f,r2,r4,s,pr,f_count,r2_count,r4_count,s_count,p_count,n);
   
    return 0;
}