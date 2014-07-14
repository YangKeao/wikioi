#include <iostream>
using namespace std;
int a[4][4];
int top,end,ans;
struct node
{
	int ans;
	int m[4][4];
};
node head[1000];
string mmmm;
int pan(int m[4][4]){
	if(m[1][1]==1&&m[1][2]==2&&m[1][3]==3&&m[2][1]==8&&m[2][2]==0&&m[2][3]==4&&m[3][1]==7&&m[3][2]==6&&m[3][3]==5)
		return 1;
	else return 0;
}
int main(){
	cin>>mmmm;
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
		a[i][j]=mmmm[i*3+j-3-48];
	}
	head[0].ans=0;
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
		head[0].m[i][j]=a[i][j];
	while(top!=end+1){
		int t,g,k=head[top].ans;
		if(pan(head[top].m)) {
			cout<<head[top].ans;
			return 0;
		}
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(a[i][j]==0) 
			{
				t=i;
				g=j;
			}
		if(t>1)  {
			head[end++].m[t][g]=head[end++].m[t-1][g];
			head[end].m[t-1][g]=0;
			head[end].ans=head[top].ans+1;
		}
		if(t<3){
			head[end++].m[t][g]=head[end++].m[t+1][g];
			head[end].m[t+1][g]=0;
			head[end].ans=head[top].ans+1;
		}
		if(g>1){
			head[end++].m[t][g]=head[end++].m[t][g-1];
			head[end].m[t][g-1]=0;
			head[end].ans=head[top].ans+1;
		}
		if(g<3){
			head[end++].m[t][g]=head[end++].m[t][g+1];
			head[end].m[t][g+1]=0;
			head[end].ans=head[top].ans+1;
		}
		top++;
	}
	return 0;
}