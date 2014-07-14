#include <iostream>
#include <queue>
#include <cstdio>
#define MAX 4996000
#define N 10100
using namespace std;

int n,m,t,g,b,path[N];

struct Edge
{
	int u,v,c,next;
}edge[MAX];
int head[N],e=1;
void build(int u,int v,int c){
	edge[e].u=u;edge[e].v=v;
	edge[e].c=c;edge[e].next=head[u];
	head[u]=e++;
}


bool inq[N];
int dist[N];
queue<int> q;
void spfa(int s,int a,int b){
	for(int i=1;i<=n;i++) dist[i]=99999999;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if((u==a&&v==b)||(u==b&&v==a)) continue;
			if(dist[v]>dist[u]+edge[i].c){
				path[u]=v;
				dist[v]=dist[u]+edge[i].c;
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
	spfa(n,0,0);
	int max=0;
	for(int i=n;i!=1;i=path[i]){
		int v=path[i];
		spfa(n,i,v);
		if(max<dist[1]) max=dist[1];
	}
	return max;
}
int main(){
	init();
	printf("%d\n",run());
	return 0;
}