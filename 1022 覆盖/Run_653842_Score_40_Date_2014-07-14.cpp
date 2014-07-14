#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 5000 
using namespace std;
int edge[MAX][MAX],nx,ny,k;
int cx[MAX],cy[MAX];
bool mk[MAX];
bool poool[MAX];
int n,m,t,g;
int path(int u){
	for(int v=1;v<=ny;v++){
		if(edge[u][v]&&!mk[v]){
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
int main(){
	scanf("%d%d%d",&n,&m,&k);
	nx=ny=n*m-k;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&t,&g);
		poool[(t-1)*m+g]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int qqq=(i-1)*m+j;
			if(poool[qqq]) continue;
			else{
				if(!poool[qqq-m]) edge[qqq][qqq-m]=1;
				if(!poool[qqq+m]) edge[qqq][qqq+m]=1;
				if(!poool[qqq-1]) edge[qqq][qqq-1]=1;
				if(!poool[qqq+1]) edge[qqq][qqq+1]=1;
			}
		}
	}
	printf("%d",MaxMatch());
	return 0;
}