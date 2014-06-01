#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
	cin >> n;
    int k=(int)floor((sqrt(8.0*n+1)-1)/2-1e-9)+1;
    int s=k*(k+1)/2;
	cout << s-n+1<<k-s+n;
    return 0;
}