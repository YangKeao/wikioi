#include<iostream>
using namespace std;
int v,i,j,n,m,a[20010];
int max(int i,int j){return i>j?i:j;}
int main()
{
    cin>>m>>n;
	for(i=1;i<=n;i++)
	{
        cin>>v;
		for(j=m;j>=v;j--)
		a[j]=max(a[j],a[j-v]+v);
	}
    cout << m-a[m];
}