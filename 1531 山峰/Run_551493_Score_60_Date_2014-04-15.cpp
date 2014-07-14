#include <iostream>
#include <stack>
using namespace std;
stack<int> q;
int n,s;
int t;
int main(){
	cin>>n;
    q.push(1000000);
    for(int i=1;i<=n;i++)
    {
        s=s+q.size()-1;
        cin>>t;
        while(t>q.top()) q.pop();
        q.push(t);
    }
    cout<<s;
	return 0;
}