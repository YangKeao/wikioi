#include <iostream>
#include <map>
using namespace std;
map<unsigned long long,unsigned long long,less<float> > a;
map<unsigned long long,unsigned long long,less<float> >::iterator pos;
int n,p;
int t;
int main(){
	cin>>n>>p;
    for(int i=1;i<=n;i++){
    	cin>>t;
        a[t]=t*p;
    }
    for(pos=a.begin();pos!=a.end();pos++){
    	t=pos ->second;
    	if(a[t]!=NULL){
    		a.erase(t);
        	n--;
    	}	
    }
    cout<<n;
	return 0;
}
