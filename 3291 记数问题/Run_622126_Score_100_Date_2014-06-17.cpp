#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int n,x,ans;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
	    stringstream ss;
	    ss<<i;
	    string t=ss.str();
	    int g=t.length();
	    for(int j=0;j<=g-1;j++){
	    	if((t[j]-48)==x) ans++;
	    }
	}
    cout<<ans;
	return 0;
}