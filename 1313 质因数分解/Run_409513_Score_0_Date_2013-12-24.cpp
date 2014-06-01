#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=sqrt(n);i++)
    {
    	if(n%i==0) cout<<n/i;
    }
    return 0;
}