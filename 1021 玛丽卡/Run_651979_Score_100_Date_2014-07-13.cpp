#include <iostream>
#include <queue>
#include <cstdio>
#include <ctype.h>
#define MAX 4996000
#define N 10100
using namespace std;

int n,m,t,g,b,path[N];


template <class T>
static void read(T &rec)
{
 	rec=0;
    char c;
    while((c=getchar())<'0' || c>'9');
    while(c>='0' && c<='9')
    {
    	rec=(rec<<3)+(rec<<1)+(c-'0');
        c=getchar();
    }
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
				path[v]=u;
				dist[v]=dist[u]+edge[i].c;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
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
	read<int> (n);
	read<int> (m);
	for(int i=1;i<=m;i++){
		read<int> (t);
		read<int> (g);
		read<int> (b);
		build(t,g,b);
		build(g,t,b);
	}
}

int run(){
	spfa(n);
	int max=0;
	for(int i=1;i!=n;i=path[i]){
		int v=path[i];
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