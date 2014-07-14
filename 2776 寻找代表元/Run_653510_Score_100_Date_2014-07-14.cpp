#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 400
using namespace std;
int edge[MAX][MAX],nx,ny;
int cx[MAX],cy[MAX];
bool mk[MAX];
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
int maxx=0,qqqqq;
int main(){
	scanf("%d%d",&n,&m);
	nx=n;
	for(int i=1;i<=n;i++){
		while(1){
			scanf("%d",&t);
			if(t==0) break;
			else {
				if(maxx<t) maxx=t;
				edge[i][t]=1;
			}
		}
	}
	ny=maxx+5;
	printf("%d",MaxMatch());
	return 0;
}