#include <stdio.h>
struct time
{
    int hr, mi, sec;
};
int main()
{
    int n, i, min, max;
    scanf("%d", &n);
    struct time x[n], diff;
    for(i=0; i<n; i++)
    {
        scanf("%d:%d:%d", &x[i].hr, &x[i].mi, &x[i].sec);
    }
    for(i=0; i<n; i++)
    {
        if(x[i].hr>x[max].hr)
        {
            max=i;
        }
        else if(x[i].hr==x[max].hr)
        {
            if(x[i].mi>x[max].mi)
            max=i;
            else if(x[i].sec>x[max].sec)
            max=i;
        }
        if(x[i].hr<x[min].hr)
        {
            min=i;
        }
        else if(x[i].hr==x[min].hr)
        {
            if(x[i].mi<x[min].mi)
            min=i;
            else if(x[i].sec<x[min].sec)
            min=i;
        }
    }
    diff.hr = x[max].hr - x[min].hr;
    diff.mi = x[max].mi  - x[min].mi;
    diff.sec = x[max].sec - x[min].sec;
    printf("%02d:%02d:%02d", diff.hr, diff.mi, diff.sec);
}