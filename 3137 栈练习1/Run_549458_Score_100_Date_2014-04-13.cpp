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
        else if(t==2) zhan.pop();
    }
    if(zhan.empty())cout <<"impossible!";
    else cout<<zhan.top();
	return 0;
}