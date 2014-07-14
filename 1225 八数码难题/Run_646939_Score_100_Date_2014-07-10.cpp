#include <iostream>
#include <cstdio>
using namespace std;
inline void swap(int &x,int &y){int t=x;x=y;y=t;}
inline int abs(int x){if(x<0)return -x;return x;}
const int d[4][2]={0,1,0,-1,1,0,-1,0},T[9][2]={2,2, 1,1, 1,2,1,3, 2,3, 3,3,3,2, 3,1, 2,1};
int qq[5][5],x0,y0,maxd,suc;
int GetH()
{
	int w=0;
	for(int x=1;x<=3;x++)
	for(int y=1;y<=3;y++)
	{
		int k=qq[x][y];
		if(k!=0) w+=abs(x-T[k][0])+abs(y-T[k][1]);
	}
	return w;
}
void init(){
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
		qq[i][j]=getchar();
		qq[i][j]-='0';
		if(qq[i][j]==0) {
			x0=i;
			y0=j;
		}
	}
}
void dfs(int x,int y,int g){
	int f=g+GetH();
	if(f>maxd) return ;
	if(f==g){suc=1;return;}
	for(int i=0;i<=3;i++){
		int dx=x+d[i][0];
		int dy=y+d[i][1];
		if(1<=dx && dx<=3 && 1<=dy && dy<=3)
		{
			swap(qq[x][y],qq[dx][dy]);
			dfs(dx,dy,g+1);
			if(suc) return;
			swap(qq[x][y],qq[dx][dy]);
		}
	}
}
void IDAStar(){
	maxd=0;
	while(!suc){
		maxd++;
		dfs(x0,y0,0);
	}
	cout<<maxd;
}
int main(){
	init();
	IDAStar();
	return 0;
}