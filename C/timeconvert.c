#include <stdio.h>
#include <string.h>

int main ()
{
    int hr=0,mn=0,sec=0;
    char T;
    scanf("%d:%d:%d%cM",&hr,&mn,&sec,&T);
    if(T=='A'&&hr>0&&hr<12)printf("%02d:%02d:%02d",hr,mn,sec);
    if(T=='A'&&hr==12)printf("00:%02d:%02d",mn,sec);
    if(T=='P'&&hr!=12)printf("%02d:%02d:%02d",(hr+12),mn,sec);
    if(T=='P'&&hr==12)printf("%02d:%02d:%02d",hr,mn,sec);
  return 0;
}