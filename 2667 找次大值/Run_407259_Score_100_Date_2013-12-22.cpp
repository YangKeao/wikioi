#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
int main()
{
    int n,max=-1000,k,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>max) {max=a[i];k=i;}
	}
	a[k]=-1000;
	max=-1000;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>max) {max=a[i];k=i;}
	}
	cout << max;
	return 0;
}