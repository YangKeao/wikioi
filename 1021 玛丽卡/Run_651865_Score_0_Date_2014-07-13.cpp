#include <iostream>
#include <queue>
#include <cstdio>
#define MAX 4996000
#define N 10100
#define INF 99999999
using namespace std;

int n,m,t,g,b,path[N];

struct Edge
{
	int u,v,next;
}edge[MAX];
int head[N],e=1;
int cc[N][N];
void build(int u,int v,int c){
	edge[e].u=u;edge[e].v=v;edge[e].next=head[u];
	cc[u][v]=c;
	head[u]=e++;
}


bool inq[N];
int dist[N];
queue<int> q;
int zz=0;
void spfa(int s){
	for(int i=1;i<=n;i++) dist[i]=99999999;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(dist[v]>dist[u]+cc[edge[i].u][edge[i].v]){
				dist[v]=dist[u]+cc[edge[i].u][edge[i].v];
				path[u]=v;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}

void init(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&t);
		scanf("%d",&g);
		scanf("%d",&b);
		build(t,g,b);
		build(g,t,b);
	}
}

int run(){
	spfa(n);
	int max=0;
	for(int i=n;i>1;i=path[i]){
		int v=path[i];
		t=cc[i][v];
		cc[i][v]=INF;
		spfa(n);
		if(max<dist[1]) max=dist[1];
		cc[i][v]=t;
	}
	return max;
}
int main(){
	init();
	printf("%d\n",run());
	return 0;
}