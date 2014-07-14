#include<iostream>
using namespace std;
int n,ans=-1;
int x,y;
int x1[15000],y1[15000],x2[15000],y2[15000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    	if(x1[i]+x2[i]>=x&&y1[i]+y2[i]>=y&&x1[i]<=x&&y1[i]<=y)ans=i;
    cout<<ans;
    return 0;
}