#include <iostream>
#include <cstdio>
#include <queue>
#define N 110
#define MAX 100000
using namespace std;
int n,p,c[N],U[N],t,g,b,first[N],tn;
bool bb[N];

struct node
{
	int u,v,c,next;
}edge[MAX];

int cend[N];

int head[N],e=1;
void build(int u,int v,int c){
	edge[e].u=u;edge[e].v=v;
	edge[e].c=c;
	edge[e].next=head[u];
	head[u]=e++;
}

queue<int> q;
bool inq[N];
void gogo(){
	for(int i=1;i<=tn;i++){
		q.push(first[i]);
		inq[first[i]]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		if(!bb[u]){
			c[u]-=U[u];
			bb[u]=true;
		}
		if(head[u]!=0&&c[u]>0){
			for(int i=head[u];i;i=edge[i].next){
				int v=edge[i].v;
				c[v]+=c[u]*edge[i].c;
				if(!inq[v])
				{
					q.push(v);
					inq[v]=1;
				}
			}
		}
		else if(head[u]==0){
			cend[u]=c[u];
		}
	}
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&U[i]);
		if(c[i]==1) {
			first[++tn]=i;
			U[i]=0;
		}
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d%d",&t,&g,&b);
		build(t,g,b);
	}
	
	gogo();

	bool k=false; 
	cout<<endl<<endl<<endl;
	for(int i=1;i<=N;i++){
		if(cend[i]!=0){
			k=true;
			printf("%d %d\n",i,cend[i]);
		}
	}
	if(!k) printf("NULL");
	return 0;
}