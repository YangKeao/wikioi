#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
int n,m,t,g;
double dist[150000];
bool inq[150000];
 
 
struct Edge{
	int u,v,next;
	double c;
}edge[150000];
struct P{
	int a,b;
}point[150000];
int e=0,head[150000];
 
 
void addnote(int u,int v,double c){
	e++;
	edge[e].u=u;
	edge[e].v=v;
	edge[e].c=c;
	edge[e].next=head[u];
	head[u]=e;
}
 
 
queue<int> q;
void spfa(int s){
	for(int i=2;i<=n;i++) dist[i]=99999999;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i!=0;i=edge[i].next){
			int v=edge[i].v;
			if(dist[v]>dist[u]+edge[i].c)
			{
				dist[v]=dist[u]+edge[i].c;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
int a,b;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&point[i].a,&point[i].b);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&t,&g);
		double c=sqrt((point[t].a-point[g].a)*(point[t].a-point[g].a)+(point[t].b-point[g].b)*(point[t].b-point[g].b));
		addnote(t,g,c);
		addnote(g,t,c);
	}
	scanf("%d%d",&a,&b);
	spfa(a);
	printf("%.2lf",dist[b]);
	return 0;
}