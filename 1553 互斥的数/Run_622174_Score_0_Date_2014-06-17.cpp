#include <iostream>
using namespace std;
unsigned long long n,p;
bool a[10000000];
unsigned long long t,maxx=0,minn=100000001;
int main(){
    cin>>n>>p;
    for(long long i=1;i<=n;i++) {
        cin>>t;a[t]=1;
        if(t>maxx) maxx=t;
        if(t<minn) minn=t;
    }
    long long k=10000000/p;
    for(long long i=minn;i<=maxx;i++){
    	if(a[i]==0) continue;
    	else {
    		if(a[i]>k) continue;
    		else if(a[a[i]*p]==0) {
    			continue;
    		}
    		else {
    			a[a[i]*p]=0;
    			a[t]=0;
    			n--;
    		}
    	}
    }
    cout<<n;
	return 0;
}
