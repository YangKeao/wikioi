#include<iostream>
#include<algorithm>
using namespace std;
int l,s,t,m,d0[110],d[110],f[20000],g[20000],ans=200000,i,j;
int main()
{
    cin>>l>>s>>t>>m;
	for(i=1;i<=m;i++) cin>>d0[i];
	sort(d0+1,d0+m+1);
	if(s!=t)
	{
		for(i=1;i<=m;i++)
		{
			if(d0[i]-d0[i-1]>25) d[i]=d[i-1]+25;
			else d[i]=d[i-1]+(d0[i]-d0[i-1]);
			g[d[i]]=1;
		}
		l=d[m];
		for(i=1;i<=l+t;i++) f[i]=2000000;
		for(i=1;i<=l+t;i++)
				for(j=s;j<=t;j++)
					if(i-j>=0) f[i]=min(f[i],f[i-j]+g[i]);
		for(i=0;i<=t;i++) ans=min(ans,f[l+i]);
	}
	else
	{ans=0;
	 for(i=1;i<=m;i++)if(d0[i]%s==0) ans++;}
	cout<<ans;
	return 0;
}