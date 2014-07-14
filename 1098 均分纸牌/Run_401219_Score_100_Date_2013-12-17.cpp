#include <iostream>
using namespace std;
int m[10000];
int n;
int main(){
	cin >> n;
	int sum=0;
	for(int i=1;i<=n;i++)
		{
		cin>>m[i];
		sum=sum+m[i];
		}
	int k=sum/n;
	int tot=0;
	for(int i=1;i<=n;i++)
	{	if(m[i]>k)
		{
			int j=m[i]-k;
			m[i]=m[i]-j;
			m[i+1]=m[i+1]+j;
			tot++;
		}
		if(m[i]<k)
		{
			int j=k-m[i];
			m[i]=m[i]+j;
			m[i+1]=m[i+1]-j;
			tot++;
		}
	}
	cout << tot;
	return 0;
}