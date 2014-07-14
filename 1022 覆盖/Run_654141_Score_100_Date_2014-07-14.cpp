#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 5000 
using namespace std;
const int maxn = 40000+100 ;
int k,tot=1,head[maxn],lin[MAX],T,n,m,t,g,dx[] = {0 , 0 , -1 , 1},dy[] = {1 , -1 , 0 , 0};
int vis[MAX];
int nx,ny,res=1;

struct node
{
	int v,next;
}e[maxn];

void add(int u,int v){
	e[tot].v=v;
	e[tot].next=head[u];
	head[u]=tot++;
}

bool find(int u){
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(vis[v]==T) continue;
		vis[v]=T;
		if(!lin[v]||find(lin[v])){
			lin[v]=u;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&t,&g);
		vis[(t-1)*m+g-1]=-1;
	}
	for(int i=0;i<n;i++){
		for(int j=i%2;j<m;j+=2)
			if(vis[i*m+j]!=-1){
				head[res]=-1;
				for(int k=0;k<=3;k++){
					int nx=i+dx[k],ny=j + dy[k];
					if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if(vis[nx*m+ny]==-1) continue ;
					add(res,nx*m+ny);
			}
			res++;
		}
	}
	int ans=0;
	for(int i=1;i<res;i++){
		T=i;
		if(find(i)) ans++ ;
	}
	printf("%d\n",ans);
	return 0;
}