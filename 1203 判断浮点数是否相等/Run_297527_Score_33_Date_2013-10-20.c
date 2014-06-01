#include<stdio.h>
#include<math.h>
int main()
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	if(abs(a-b)<=0.00000001)printf("yes");
	else printf("no");
	return 0;
}