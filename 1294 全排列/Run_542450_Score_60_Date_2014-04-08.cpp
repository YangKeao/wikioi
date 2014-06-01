#include <iostream>
#include <algorithm> 
using namespace std;
int n;
int a[1000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	a[i-1]=i;
    }
    for(int i=1;i<=n-1;i++) 
    {
        cout<<a[i-1]<<" ";
    }
    cout<<a[n-1];
    cout<<endl;
    while(next_permutation(a,a+n)){
    	for(int i=1;i<=n-1;i++)
        {
            cout<<a[i-1]<<" ";
        }
        cout<<a[n-1];
        cout<<endl;
    }
    return 0;
}