#include <iostream>
using namespace std;
long long k=1,ans=0;
long long n,q=1,f=1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ans=ans+k;
        if(q==f) {
            k=k*2;
            f=f+1;
            q=1;
            continue;
        }
        q++;
    }
    cout<<ans%10000;
	return 0;
}