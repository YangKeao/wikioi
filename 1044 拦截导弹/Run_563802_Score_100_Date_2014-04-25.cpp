#include <iostream>
using namespace std;
int n,h[50],len=0,mx,ml=1;
int t[50];
int f[50];
int main(){
    while(cin>>h[++len]);
    len--;
    for(int i=len;i>=1;i--)
    {
        mx=0;
        for(int j=i+1;j<=len;j++)
        {
            if(h[j]<=h[i]&&mx<t[j]) {
            	mx=t[j];
            }
        }
        t[i]=1+mx;
    }
    mx=0;
    for(int i=1;i<=len;i++) if(mx<t[i]) mx=t[i];
    for(int i=len;i>=1;i--)
    {
        ml=0;
        t[i]=1;
        for(int j=i+1;j<=len;j++)
        {
            if(h[j]>h[i]&&ml<t[j]) {
            	ml=t[j];
            }
        }
        t[i]=1+ml;
    }
    ml=0;
    for(int i=1;i<=len;i++) if(ml<t[i]) ml=t[i];
    cout<<mx<<endl<<ml;
	return 0;
}