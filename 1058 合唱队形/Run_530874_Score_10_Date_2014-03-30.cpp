#include <iostream>
using namespace std;
int ma,n,t[150];
int mb;
int f[150];
int q[150];
int en[150];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=n;i++)//断点
    {
        //最长下降子序列
    	for(int j=i;j>=1;j--)//判断点
        {
            ma=0;
            for(int m=j;m<=i;m++)//小判断
            {
                if(t[j]>t[m]&&f[m]>ma) ma=f[m];
            }
            f[j]=ma+1;
        }
        ma=1;
        for(int j=1;j<=i;j++)
        	if(f[j]>ma) ma=f[j];
        //cout<<ma;
        //最长上升子序列
    	for(int j=n;j>=i;j--)//判断点
        {
            mb=0;
            for(int m=n;m>=j;m--)//小判断
            {
                if(t[j]<t[m]&&q[m]>mb) mb=q[m];
            }
            q[j]=mb+1;
        }
        mb=1;
        for(int k=i;k<=n;k++)
            if(q[k]>mb) mb=q[k];
        //cout<<mb;
        en[i]=mb+ma-1;
    }
    mb=1;
    for(int i=1;i<=n;i++) if(en[i]>mb) mb=en[i];
    cout<<n-mb;
    return 0;
}