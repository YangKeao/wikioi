#include<iostream>
#include<algorithm>
using namespace std;
int a[500];
int cmp( const int &a, const int &b ){
    if( a > b )
       return 1;
    else
       return 0;
}
int main()
{
    int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp); 
	cout<<a[1];
}