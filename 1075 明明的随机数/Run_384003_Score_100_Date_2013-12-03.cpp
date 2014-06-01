#include<stdio.h>
#include<string.h>
int main()
{
     int i,m,n,s=0,a[1001];
     memset(a,0,sizeof(a));
     scanf("%d",&n);
     for (i=1;i<=n;i++)
         {scanf("%d",&m); a[m]=1;}
     for (i=1;i<=1000;i++)
         if (a[i]==1) s++;
     printf("%d\n",s);
     for (i=1;i<=1000;i++)
         if (a[i]==1) printf("%d ",i);
}