#include <iostream>
#include <stack>
using namespace std;
stack<int> zhan;
int n;
int t,g;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>t;
        if(t==1) {cin>>g;zhan.push(g);}
        else if(t==2&&(!zhan.empty())) zhan.pop();
        else if(t==2&&zhan.empty()) {cout<<"impossible!";return 0;}
        else if(t==3) cout<<zhan.top()<<endl;
    }
    if(zhan.empty())cout <<"impossible!";
	return 0;
}