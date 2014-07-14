#include<stdio.h>

int main()
{
	int n;
	int a,sum=0;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum = sum + a;
	}
	printf("%d",sum);
}