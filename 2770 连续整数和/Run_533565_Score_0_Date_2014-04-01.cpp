#include <iostream>
using namespace std;
int n,k;
int t,i;
int main(){
    cin>>n>>k;
    for(i=1;;i++)
    {
    	t=(i+k)*k/2;
        if(t==n) break;
    }
    for(int j=1;j<=k;j++)
        cout<<i+j-1<<" ";
	return 0;
}