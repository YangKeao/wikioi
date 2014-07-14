#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 5000 
using namespace std;
int nx,ny,k;
int cx[MAX],cy[MAX];
bool mk[MAX];
bool pool[MAX];
int n,m,t,g;


struct Node
{
	int v,next;
}edge[500000];
int e=1,head[MAX];
void addnote(int u,int v){
	edge[e].v=v;
	edge[e].next=head[u];
	head[u]=e++;
}

int path(int u){
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(!mk[v]){
			mk[v]=1;
			if(cy[v]==-1||path(cy[v])){
				cx[u]=v;
				cy[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch(){
	int ans=0;
	memset(cx,0xff,sizeof(cx));
	memset(cy,0xff,sizeof(cy));
	for(int i=1;i<=nx;i++){
		if(cx[i]==-1){
			memset(mk,0,sizeof(mk));
			ans+=path(i);
		}
	}
	return ans;
}

int xx,yy;
int dx[4] = {0 , 0 , -1 , 1} ;
int dy[4] = {1 , -1 , 0 , 0} ;
int nnx,nny,res;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&t,&g);
		pool[(t-1)*m+g]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i%2;j<=m;j+=2){
			int qq=(i-1)*m+j;
			
			if(pool[qq]) {
				head[qq]=-1;
				continue;
			}
			else{
				for(int k=0;k<=3;k++){
					int nnx=i+dx[k],nny=j + dy[k];
					if(nnx < 0 || nny < 0 || nnx >= m || nny >= n)continue;
					if(pool[(nnx-1)*m+nny] == -1) continue ;
					addnote(qq,(nnx-1)*m+nny);
				}
				res++;
			}
		}
	}
	nx=ny=res+5;
	printf("%d",MaxMatch());
	return 0;
}