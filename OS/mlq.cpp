#include <iostream>
using namespace std;

struct fcfs{
    int pid, bt, ct, tat, wt, rmt, rst;
};

struct rr2{
    int pid, bt, ct, tat, wt, rmt, rst;
};

struct rr4{
    int pid, bt, ct, tat, wt, rmt, rst;
};

struct sjf{
    int pid, bt, ct, tat, wt, rmt, rst;
};

struct priority{
    int pid, bt, pr, ct, tat, wt, rmt, rst;
};

struct Process
{
    int pid, type, bt, pr, ct, tat, wt, rmt, rst;
};

int totalwt=0, totaltat=0;

int fcfs_func(fcfs f[], int fcount,int time);
int rr2_func(rr2 r2[], int rr2_count,int time);
int rr4_func(rr4 r4[], int rr4_count, int time);
int sjf_func(sjf s[], int sjf_count, int time);
int prt_func(priority p[], int priority_count,int time);
int mlq_func(fcfs f[], rr2 r2[], rr4 r4[], sjf s[], priority p[], int fcount, int rr2_count, int rr4_count, int sjf_count, int priority_count, int n);

int main()
{
    int n;
    cout<<"Queue No.\tProcess Type\t\t\tScheduling Algorithm"<<endl<<"1\t\tSystem process\t\t\tFCFS"<<endl;
    cout<<"2\t\tInteractive processes\t\tRound Robin with TQ: 2"<<endl;
    cout<<"3\t\tInteractive editing processes\tRound Robin with TQ: 4"<<endl;
    cout<<"4\t\tBatch processes\t\t\tSJF"<<endl;
    cout<<"5\t\tStudent processes\t\tPriority scheduling"<<endl<<endl;
    cout<<"Enter total number of processes: ";    
    cin>>n;
    Process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        p[i].pid=i+1;
        cout<<"For process P"<<(i+1)<<endl;
        cout<<"Enter the type of process: ";
        cin>>p[i].type;
        switch (p[i].type)
        {
        case 1:
            cout<<"Enter Burst Time: ";
            cin>>p[i].bt;
            break;
        case 2:
            cout<<"Enter Burst Time: ";
            cin>>p[i].bt;
            break;
        case 3:
            cout<<"Enter Burst Time: ";
            cin>>p[i].bt;
            break;
        case 4:
            cout<<"Enter Burst Time: ";
            cin>>p[i].bt;
            break;
        case 5:
            cout<<"Enter Burst Time: ";
            cin>>p[i].bt;
            cout<<"Enter Priority: ";    
            cin>>p[i].pr;
            break;
        default:
            cout<<"Invalid Queue"<<endl;
            break;
        }
    }
   
    int fcount=0;
    int rr2_count=0;
    int rr4_count=0;
    int sjf_count=0;
    int priority_count=0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].type==1)
        {
            fcount++;
        }
        else if (p[i].type==2)
        {
            rr2_count++;
        }
        else if (p[i].type==3)
        {
            rr4_count++;
        }
        else if (p[i].type==4)
        {
            sjf_count++;
        }
        else if (p[i].type==5)
        {
            priority_count++;
        }
    }

    fcfs f[fcount];
    rr2 r2[rr2_count];
    rr4 r4[rr4_count];
    sjf s[sjf_count];
    priority pr[priority_count];

    int n1=0, n2=0, n3=0, n4=0, n5=0;
    
    for (int i = 0; i < n; i++)
    {
        if(p[i].type==1){
            f[n1].pid=p[i].pid;
            f[n1].bt= p[i].bt;
            n1++;
  
        }
        else if (p[i].type==2)
        {
            r2[n2].pid=p[i].pid;
            r2[n2].bt=p[i].bt;
            n2++;
 
        }
        else if (p[i].type==3)
        {
            r4[n3].pid=p[i].pid;
            r4[n3].bt=p[i].bt;
            n3++;
      
        }
        else if (p[i].type==4)
        {
            s[n4].pid=p[i].pid;
            s[n4].bt=p[i].bt;
            n4++;
           
        }
        else if (p[i].type==5)
        {
            pr[n5].pid=p[i].pid;
            pr[n5].bt=p[i].bt;
            pr[n5].pr=p[i].pr;
            n5++;

        }  
    }
    mlq_func(f,r2,r4,s,pr,fcount,rr2_count,rr4_count,sjf_count,priority_count,n);
    return 0;
}

int fcfs_func(fcfs f[], int fcount,int time){
    for (int i = 0; i < fcount; i++)
    {
        f[i].ct=0;
        f[i].tat=0;
        f[i].wt=0;
        f[i].rst=0;
        f[i].ct=time+f[i].bt;
        time=f[i].ct;
        f[i].tat=f[i].ct;
        f[i].wt=f[i].tat-f[i].bt;
        f[i].rst=f[i].wt;
        totalwt=totalwt+f[i].wt;
        totaltat=totaltat+f[i].tat;
    }
    
    for (int i = 0; i < fcount; i++)
    {
        cout<<"P"<<f[i].pid<<"\t"<<f[i].bt<<"\t\t"<<f[i].ct<<"\t\t"<<f[i].tat<<"\t\t\t"<<f[i].wt<<"\t\t"<<endl;
    }
    return time;
}

int rr2_func(rr2 r2[], int rr2_count,int time){
    for (int i = 0; i < rr2_count; i++)
    {
        r2[i].ct=0;
        r2[i].tat=0;
        r2[i].wt=0;
        r2[i].rst=0;
        r2[i].rmt=r2[i].bt;
    }
    bool flag=false;
    while (flag==false)
    {
        flag=true;
        for (int i = 0; i < rr2_count; i++)
        {
            if (r2[i].rmt>2)
            {
                time+=2;
                r2[i].rmt-=2;
                flag=false;
            }
            else if (r2[i].rmt>0)
            {
                time+=r2[i].rmt;
                r2[i].rmt=0;
                r2[i].ct=time;
                r2[i].tat=r2[i].ct;
                r2[i].wt=r2[i].tat-r2[i].bt;
                r2[i].rst=r2[i].wt;
                totalwt=totalwt+r2[i].wt;
                totaltat=totaltat+r2[i].tat;
            }
        }
    }
    
    
    for (int i = 0; i < rr2_count; i++)
    {
        cout<<"P"<<r2[i].pid<<"\t"<<r2[i].bt<<"\t\t"<<r2[i].ct<<"\t\t"<<r2[i].tat<<"\t\t\t"<<r2[i].wt<<"\t\t"<<endl;
    }
    return time;
}


int rr4_func(rr4 r4[], int rr4_count, int time){
    for (int i = 0; i < rr4_count; i++)
    {
        r4[i].ct=0;
        r4[i].tat=0;
        r4[i].wt=0;
        r4[i].rst=0;
        r4[i].rmt=r4[i].bt;
    }
    bool flag=false;
    while (flag==false)
    {
        flag=true;
        for (int i = 0; i < rr4_count; i++)
        {
            if (r4[i].rmt>4)
            {
                time+=4;
                r4[i].rmt-=4;
                flag=false;
            }
            else if (r4[i].rmt>0)
            {
                time+=r4[i].rmt;
                r4[i].rmt=0;
                r4[i].ct=time;
                r4[i].tat=r4[i].ct;
                r4[i].wt=r4[i].tat-r4[i].bt;
                r4[i].rst=r4[i].wt;
                totalwt=totalwt+r4[i].wt;
                totaltat=totaltat+r4[i].tat;
            }
        }
    }
    
    
    for (int i = 0; i < rr4_count; i++)
    {
        cout<<"P"<<r4[i].pid<<"\t"<<r4[i].bt<<"\t\t"<<r4[i].ct<<"\t\t"<<r4[i].tat<<"\t\t\t"<<r4[i].wt<<"\t\t"<<endl;
    }
    return time;
}


int sjf_func(sjf s[], int sjf_count, int time){
    for (int i = 0; i < sjf_count; i++)
    {
        s[i].ct=0;
        s[i].tat=0;
        s[i].wt=0;
        s[i].rst=0;
        s[i].rmt=s[i].bt;
    }
    bool flag=false;
    while (flag==false)
    {
        flag=true;
        for (int i = 0; i < sjf_count; i++)
        {
            if (s[i].rmt>0)
            {
                time+=s[i].rmt;
                s[i].rmt=0;
                s[i].ct=time;
                s[i].tat=s[i].ct;
                s[i].wt=s[i].tat-s[i].bt;
                s[i].rst=s[i].wt;
                totalwt=totalwt+s[i].wt;
                totaltat=totaltat+s[i].tat;
            }
        }
    }
    
    
    for (int i = 0; i < sjf_count; i++)
    {
        cout<<"P"<<s[i].pid<<"\t"<<s[i].bt<<"\t\t"<<s[i].ct<<"\t\t"<<s[i].tat<<"\t\t\t"<<s[i].wt<<"\t\t"<<endl;
    }
    return time;
}


int prt_func(priority p[], int priority_count,int time){
    for (int i = 0; i < priority_count; i++)
    {
        p[i].ct=0;
        p[i].tat=0;
        p[i].wt=0;
        p[i].rst=0;
        p[i].rmt=p[i].bt;
    }
    bool flag=false;
    while (flag==false)
    {
        flag=true;
        for (int i = 0; i < priority_count; i++)
        {
            if (p[i].rmt>0)
            {
                time+=p[i].rmt;
                p[i].rmt=0;
                p[i].ct=time;
                p[i].tat=p[i].ct;
                p[i].wt=p[i].tat-p[i].bt;
                p[i].rst=p[i].wt;
                totalwt=totalwt+p[i].wt;
                totaltat=totaltat+p[i].tat;
            }
        }
    }
    for (int i = 0; i < priority_count; i++)
    {
        cout<<"P"<<p[i].pid<<"\t"<<p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tat<<"\t\t\t"<<p[i].wt<<"\t\t"<<endl;
    }
    return time;
}

int mlq_func(fcfs f[], rr2 r2[], rr4 r4[], sjf s[], priority p[], int fcount, int rr2_count, int rr4_count, int sjf_count, int priority_count, int n){
    int time=0;
    cout<<endl;
    cout<<"Table"<<endl;
    cout<<"PID\tBurst Time\tCompletion Time\tTurn Around Time\tWait Time\t"<<endl;
    time=fcfs_func(f,fcount,time);
    time=rr2_func(r2,rr2_count,time);
    time=rr4_func(r4,rr4_count,time);
    time=sjf_func(s,sjf_count,time);
    time=prt_func(p,priority_count,time);
    float avgwt=(float)totalwt/n;
    float avgtat=(float)totaltat/n;
    cout<<endl<<"Average Waiting Time : "<<avgwt;
    cout<<endl<<"Average Turn-Around Time Time : "<<avgtat;
    return 0;
}