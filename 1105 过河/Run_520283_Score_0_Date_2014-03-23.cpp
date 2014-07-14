#include <iostream>
#include <algorithm>
using namespace std;
int s,t,l,m;
int z[110],f[110],shi[110];
int q,w,shitou=1,g;
int main(){
    cin>>l>>s>>t>>m;
    for(int i=1;i<=m;i++)
    {cin>>z[i];}
    sort(z,z+m+1);
    for(int i=1;i<=m;i++)
    {

        shi[z[i]]=1;
    }
    for(int i=1;i<=s;i++) f[i]=50;
    for(int i=2;i<=l+t;i++)
    for(int j=s;j<=t;j++)
    {
        if(i-j<0) {f[i]=50;}
        else{
        	g=f[i-j]+shi[i];
            //cout<<g<<endl;
            if(f[i]>0)
            	f[i]=f[i]<g?f[i]:g;
            else f[i]=g;
        }
    }
    w=50000;
    //for(int i=1;i<=l+t;i++) cout<<f[i]<<endl;
    for(int i=l;i<=l+t;i++)
        if(f[i]<w) w=f[i];
    cout<<w;
    return 0;
}