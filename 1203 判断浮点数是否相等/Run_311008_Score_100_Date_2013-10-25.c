#include <stdio.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf",&a,&b);
	if(a-b>0) c=a-b;
	else c=b-a;
	if(c<=1e-8) printf ("yes");
	else printf ("no");
	return 0;
}