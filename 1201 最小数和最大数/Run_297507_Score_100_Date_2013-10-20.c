#include<stdio.h>

int main()
{
	int n;
	int a,min,max;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(i==1){max=a;min=a;};
		if(a>max)max=a;
		if(a<min)min=a;
	}
	printf("%d %d",min,max);
}