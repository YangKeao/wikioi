#include <iostream>
#include <queue>
using namespace std;

struct info{
	int data;
};

bool operator < (info a,info b){
    return a.data>b.data;
}
int n,ans;
info x,x1,x2;
int main(){
    cin>>n;
    priority_queue<info>pq;
    for(int i=1;i<=n;i++){
        cin>>x.data;
        pq.push(x);
    }
    for(int i=1;i<n;i++){
    	x1=pq.top();
        pq.pop();
        x2=pq.top();
        pq.pop();
        ans=ans+x1.data+x2.data;
        x.data=x1.data+x2.data;
        pq.push(x);
    }
    cout<<ans;
	return 0;
}
