#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 32
#define MAXV 50010
#define inf (1<<26)

inline int readint()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}


const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

struct edge {
	edge *next;
	int t,d;
	edge () {
		next=NULL;
	}
} *head[MAXV];

void AddEdge(int s,int t,int d) {
	edge *p=new(edge);
	p->t=t,p->d=d;
	p->next=head[s];
	head[s]=p;
}

int Map[MAXN][MAXN],n,m,q,ex,ey,sx,sy,tx,ty;
int v[MAXN][MAXN][4],V=0;
int dist[MAXN][MAXN],Move[MAXN][MAXN][4][4];

int Dist[MAXV];
bool f[MAXV];

int S,T;

struct node {
	int x,y;
	node (int _x,int _y):x(_x),y(_y) {
		
	}
};
queue<node>Q;

int Bfs(int Sx,int Sy,int Tx,int Ty) {
	if (Sx==Tx&&Sy==Ty) return 0;
	while (!Q.empty()) Q.pop();
	for (int i=0;i++<n;) {
		for (int j=0;j++<m;) {
			dist[i][j]=inf;
		}
	}
	dist[Sx][Sy]=0;
	Q.push(node(Sx,Sy));
	while (!Q.empty()) {
		node u=Q.front();
		Q.pop();
		for (int i=0;i<4;i++) {
			if (Map[u.x+dir[i][0]][u.y+dir[i][1]]&&dist[u.x+dir[i][0]][u.y+dir[i][1]]==inf) {
				dist[u.x+dir[i][0]][u.y+dir[i][1]]=dist[u.x][u.y]+1;
				if (u.x+dir[i][0]==Tx&&u.y+dir[i][1]==Ty) return dist[u.x][u.y]+1;
				Q.push(node(u.x+dir[i][0],u.y+dir[i][1]));
			}
		}
	}
	return inf;
}

struct Cmp {
	bool operator()(int x,int y) {
		return Dist[x]>Dist[y];
	}
};
priority_queue<int,vector<int>,Cmp>Pq;

int spfa() {
	for (int i=0;i++<V;) Dist[i]=inf;
	memset(f,true,sizeof(f));
	while (!Pq.empty()) Pq.pop();
	Dist[S]=0;
	Pq.push(S);
	while (!Pq.empty()) {
		int u=Pq.top();
		Pq.pop();
		if (!f[u]) continue;
		f[u]=false;
		if (u==T) return Dist[T];
		for (edge *p=head[u];p;p=p->next) {
			if (Dist[p->t]>Dist[u]+p->d) {
				Dist[p->t]=Dist[u]+p->d;
				f[p->t]=true;
				Pq.push(p->t);
			}
		}
	}
	return Dist[T]<inf?Dist[T]:-1;
}

int main() {
	n=readint();
	m=readint();
	q=readint();
	memset(Map,0,sizeof(Map));
	for (int i=0;i++<n;) {
		for (int j=0;j++<m;) {
			Map[i][j]=readint();
			for (int k=0;k<4;k++) {
				v[i][j][k]=++V;
			}
		}
	}
	for (int i=0;i++<n;) {
		for (int j=0;j++<m;) {
			for (int k=0;k<4;k++) {
				for (int h=0;h<4;h++) {
					Move[i][j][k][h]=inf;
				}
			}
		}
	}
	for (int i=0;i++<n;) {
		for (int j=0;j++<m;) {
			if (Map[i][j]) {
				Map[i][j]=0;
				for (int k=0;k<4;k++) {
					if (Map[i+dir[k][0]][j+dir[k][1]]) {
						for (int h=0;h<4;h++) {
							if (Map[i+dir[h][0]][j+dir[h][1]]) {
								Move[i][j][k][h]=Bfs(i+dir[k][0],j+dir[k][1],i+dir[h][0],j+dir[h][1])+1;
							}
						}
					}
				}
				Map[i][j]=1;
			}
		}
	}
	memset(head,0,sizeof(head));
	for (int i=0;i++<n;) {
		for (int j=0;j++<m;) {
			for (int k=0;k<4;k++) {
				for (int h=0;h<4;h++) {
					if (Move[i][j][k][h]<inf) {
						AddEdge(v[i][j][k],v[i+dir[h][0]][j+dir[h][1]][h^1],Move[i][j][k][h]);
					}
				}
			}
		}
	}
	while (q--) {
		ex=readint();
		ey=readint();
		sx=readint();
		sy=readint();
		tx=readint();
		ty=readint();
		if (sx==tx&&sy==ty) {
			printf("0\n");
			continue;
		}
		S=++V;
		T=++V;
		if (Map[sx][sy]==0||Map[tx][ty]==0) {
			printf("-1\n");
			continue;
		}
		Map[sx][sy]=0;
		for (int i=0;i<4;i++) {
			if (Map[sx+dir[i][0]][sy+dir[i][1]]) {
				int D=Bfs(ex,ey,sx+dir[i][0],sy+dir[i][1]);
				if (D<inf) {
					AddEdge(S,v[sx][sy][i],D);
				}
			}
		}
		Map[sx][sy]=1;
		for (int i=0;i<4;i++) {
			if (Map[tx+dir[i][0]][ty+dir[i][1]]) {
				AddEdge(v[tx][ty][i],T,0);
			}
		}
		printf("%d",spfa());
		printf("\n");
	}
	return 0;
}
