#include <iostream>
#include <stack>
using namespace std;
stack<int> q;
int n;
int t;
int s;
int main(){
    cin>>n;
    cin>>t;
    q.push(t);
    for(int i=2;i<=n;i++)
    {
    	cin>>t;
        s=s+q.size();
        while((!q.empty())&&t>q.top())
            q.pop();
        q.push(t);
    }
    cout<<s;
	return 0;
}
