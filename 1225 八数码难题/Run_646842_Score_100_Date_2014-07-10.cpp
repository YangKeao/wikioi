#include <iostream>
#include <cstdio>
using namespace std;
const int 
	d[4][2]={0,1, 
			0,-1, 
			1,0, 
			-1,0},
	T[9][2]={
			2,2, 1,1, 1,2,
			1,3, 2,3, 3,3,
			3,2, 3,1, 2,1
			};
inline void swap(int &x,int &y){int t=x;x=y;y=t;}
inline int abs(int x){if(x<0)return -x;return x;}

int s[4][4];
int maxDepth,x0,y0;
bool success;

inline int h()
{
	int w=0;
	for(int x=1;x<=3;x++)
	for(int y=1;y<=3;y++)
	{
		int k=s[x][y];
		if(k!=0) w+=abs(x-T[k][0])+abs(y-T[k][1]);
	}
	return w;
}
void init()
{
	for(int x=1;x<=3;x++)
	 for(int y=1;y<=3;y++)
	{
		s[x][y]=getchar();
		s[x][y]-='0';
		if(s[x][y]==0)
		{
			x0=x;
			y0=y;
		}
	}
}
void dfs(int x,int y,int g)
{
	int f=g+h();
	if(f==g){success=1;return;}
	if(f>maxDepth) return;
	
	for(int i=0;i<=3;i++)
	{
		int dx=x+d[i][0],dy=y+d[i][1];
		if(1<=dx && dx<=3 && 1<=dy && dy<=3)
		{
			swap(s[x][y],s[dx][dy]);
			dfs(dx,dy,g+1);
			if(success) return;
			swap(s[x][y],s[dx][dy]);
		}
	}
}

void IdAstar()
{
	maxDepth=0;
	while(!success)
	{
		maxDepth++;
		dfs(x0,y0,0);
	}
	printf("%d\n",maxDepth);
}

int main()
{
	init();
	IdAstar();
}