#include <iostream>
#include<algorithm>
int m[100],n,num,l;
using namespace std;
int main(){
	int a;
    int max=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>m[i];
    }
    sort(m+1,m+n+1);
    for(int i=1;i<=n;i++)
    {
        l=i;
        for(int j=1;j<=(m[i]-m[1])/2;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(m[k]==m[l]+j) {l=k;num++;}
            }
            if((num+1)>=max) max=num+1;
        }
    }
    cout<<max;
    return 0;
}