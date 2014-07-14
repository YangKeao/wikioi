#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int n,m,t,g;
double disk[105][105];
bool aa[105][105];
struct Node
{
	int x,y;
}node[105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>node[i].x>>node[i].y;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t>>g;
		aa[t][g]=1;
		aa[g][t]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(aa[i][j])
			disk[i][j]=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
		else disk[i][j]=899999;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(aa[i][k]&&aa[k][j]&&(disk[i][j]>disk[i][k]+disk[k][j]))
		{
			//if(i==1&&j==5) cout<<endl<<endl<<endl<<k;
			disk[i][j]=disk[i][k]+disk[k][j];
		}
	}
	cin>>t>>g;
	printf("%.2lf",disk[t][g]);
	//cout<<disk[1][2]<<endl<<disk[2][5]<<endl;
	//cout<<disk[1][3]<<endl<<disk[3][5];
	return 0;
}