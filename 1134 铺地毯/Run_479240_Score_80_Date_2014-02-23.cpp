#include <iostream>
using namespace std;
int n,a[10000],b[10000],c[10000],d[10000],x,y,end=-1;
int main(){
	cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    {
    	if(x>=a[i]&&x<=c[i]+a[i]&&y>=b[i]&&y<=d[i]+b[i]) end=i;
    }
    cout<<end;
	return 0;
}