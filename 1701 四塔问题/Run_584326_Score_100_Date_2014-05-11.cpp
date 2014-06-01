#include <iostream>
using namespace std;
int k=1,ans=0;
int n,q=1,f=1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+k)%10000;
        if(q==f) {
            k=(k*2)%10000;
            f=(f+1)%10000;
            q=1;
            continue;
        }
        q++;
    }
    cout<<ans%10000;
	return 0;
}