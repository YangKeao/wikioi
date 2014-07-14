#include <iostream>
#include <math.h>
int n=1;
using namespace std;
int main(){
	int K;
    double q=0;
    cin>>K;
    const double c=0.5772156649015;
    while(q<=K)
    {
    	q=q+1.0/n;
    }
    cout<<n+1;
    
    return 0;
}