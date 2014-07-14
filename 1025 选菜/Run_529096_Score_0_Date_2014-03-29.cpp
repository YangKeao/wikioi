#include <iostream>
using namespace std;
double n,k,x;
double TT[110];// jiaqin
int  QQ[110];// jiazhi
int  BB[110];// bianhao
double  mo[110];
int  va[110];
int  f[110];
int t;
int main(){
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>TT[i];
    for(int i=1;i<=n;i++)
        cin>>QQ[i];
    for(int i=1;i<=n;i++)
        cin>>BB[i];
    for(int i=1;i<=n;i++)
    {
    	mo[BB[i]]=TT[i];
        va[BB[i]]=QQ[i];
    }
    for(int i=1;i<=k;i++)
    {
    	cin>>t;
        x=x-mo[t];
        mo[t]=99999999999999999;
    }
    
	return 0;
}