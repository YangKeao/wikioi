#include <iostream>
#include <string>
using namespace std;
string a;
int n,t,q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a;
        q=a.length();
        t=a[q-1];
        if(t%2==0) cout<<"even"<<endl;
        else if(t%2!=0) cout<<"odd"<<endl;
    }
	return 0;
}