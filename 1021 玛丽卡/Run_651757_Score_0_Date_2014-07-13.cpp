#include <iostream>
#include <queue>
#include <cstdio>
#include <ctype.h>
#define MAX 4996000
#define N 10100
using namespace std;

long long n,m,t,g,b,path[N];


inline long long readint()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	long long x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

long long buf[20];
inline void writeint(long long x)
{
	long long p=0;
	if(x==0)p++;
	else while(x)
	{
		buf[p++]=x%10;
		x/=10;
	}
	for(long long i=p-1;i>=0;i--)putchar('0'+buf[i]);
	return;
}


struct Edge
{
	long long u,v,c,next;
}edge[MAX];
long long head[N],e=1;
void build(long long u,long long v,long long c){
	edge[e].u=u;edge[e].v=v;
	edge[e].c=c;edge[e].next=head[u];
	head[u]=e++;
}


queue<int> q;
bool inq[N];
long long dist[N];
void spfa(long long s,long long a,long long b){
	for(long long i=1;i<=n;i++) dist[i]=99999999;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		long long u=q.front();
		q.pop();
		inq[u]=0;
		for(long long i=head[u];i;i=edge[i].next){
			long long v=edge[i].v;
			if(u==a&&v==b) continue;
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
	n=readint();
	m=readint();
	for(long long i=1;i<=m;i++){
		t=readint();
		g=readint();
		b=readint();
		build(t,g,b);
		build(g,t,b);
	}
}

long long run(){
	spfa(n,0,0);
	long long max=0;
	for(long long i=n;i>1;i=path[i]){
		long long v=path[i];
		spfa(n,i,v);
		if(max<dist[1]) max=dist[1];
	}
	return max;
}
int main(){
	init();
	writeint(run());
	return 0;
}