#include<stdio.h>
int main()
{
double a,b;
scanf("%lf %lf",&a,&b);
if(abs(a-b)<=0.000000001)printf("yes");
else printf("no");
return 0;
}