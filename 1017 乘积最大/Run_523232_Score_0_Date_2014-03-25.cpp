#include <iostream>
#include <math.h>
using namespace std;
int n,k;
string number;
int num[100];
int nn[100][100];
int f[100][100];
int main(){
    cin>>n>>k;
    cin>>number;
    for(int i=0;i<=n-1;i++)
        num[i+1]=number[i]-48;
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    for(int d=i;d<=j;d++)
        nn[i][j]=nn[i][j]+num[d]*pow(10,(j-d));
	for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
        cout<<nn[i][j]<<endl;
    
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        for(int m=j;m<=n;m++)
        
	return 0;
}