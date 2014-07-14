#include <iostream>
#include <queue>
#include <cstdio>
#define MAX 499600
#define N 1010
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
			if(dist[v]>dist[u]+edge[i].c){
				dist[v]=dist[u]+edge[i].c;
				path[u]=v;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
void spfa2(int s){
	for(int i=1;i<=n;i++) dist[i]=99999999;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].v;
			if(dist[v]>dist[u]+edge[i].c){
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
	scanf("%d%d",&n,&m);
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
	for(int i=n;i;i=path[i]){
		int v=path[i];
		int t1,t2;
		for(int j=head[i];j;j=edge[j].next){
			if(v==edge[j].v) 
			{
				t1=j;break;
			}
		}
		for(int j=head[v];j;j=edge[j].next){
			if(i==edge[j].v) 
			{
				t2=j;break;
			}
		}
		t=edge[t1].c;
		g=edge[t2].c;
		edge[t1].c=99999999;
		edge[t2].c=99999999;
		spfa2(n);
		if(max<dist[1]) max=dist[1];
		edge[t1].c=t;
		edge[t2].c=g;
	}
	return max;
}
int main(){
	init();
	printf("%d",run());
	return 0;
}