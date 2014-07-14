#include<stdio.h>
int n,ans=-1;
int x,y;
int x1[15000],y1[15000],x2[15000],y2[15000];
int main()
{
scanf("%d",&n);
for(int i=1;i<=n;i++)
scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
scanf("%d %d",&x,&y);
for(int i=1;i<=n;i++)
if(x1[i]+x2[i]>=x&&y1[i]+y2[i]>=y&&x1[i]<=x&&y1[i]<=y)ans=i;
printf("%d",ans);
return 0;
}