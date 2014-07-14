#include <iostream>
#include <queue>
#include <cstdio>
#include <ctype.h>
#define MAX 499600
#define N 1010
using namespace std;

int n,m,t,g,b,path[N];


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

int buf[20];
inline void writeint(int x)
{
	int p=0;
	if(x==0)p++;
	else while(x)
	{
		buf[p++]=x%10;
		x/=10;
	}
	for(int i=p-1;i>=0;i--)putchar('0'+buf[i]);
	return;
}


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


queue<int> q;
bool inq[N];
int dist[N];
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
	n=readint();
	m=readint();
	for(int i=1;i<=m;i++){
		t=readint();
		g=readint();
		b=readint();
		build(t,g,b);
		build(g,t,b);
	}
}

int run(){
	spfa(n);
	int max=0;
	for(int i=n;i;i=path[i]){
		int v=path[i];
		int YKA;
		for(int j=head[i];j;j=edge[j].next){
			if(v==edge[j].v) 
			{
				YKA=j;break;
			}
		}
		int t=edge[YKA].c;
		edge[YKA].c=99999999;
		spfa2(n);
		if(max<dist[1]) max=dist[1];
		edge[YKA].c=t;
	}
	return max;
}
int main(){
	init();
	writeint(run());
	return 0;
}