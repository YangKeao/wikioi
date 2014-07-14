#include<cstdio>
const int maxn = 40000+100 ;
int n , m , K , tot , T , res = 1;
int head[maxn] , vis[maxn] , lin[maxn] , q[maxn];
int dx[] = {0 , 0 , -1 , 1} ;
int dy[] = {1 , -1 , 0 , 0} ;

struct node{
	int next,v;
}e[maxn] ;

void add(int u,int v) {
	e[tot].v = v ;
	e[tot].next = head[u] ;
	head[u] = tot++ ;
}


bool find(int u) {
	for(int i = head[u] ; i != -1 ; i = e[i].next) {
		int v = e[i].v ;
		if(vis[v] == T) continue ;
		vis[v] = T ;
		if(!lin[v] || find(lin[v])) {
			lin[v] = u ;
			return true ;
		}
	}
	return false ;
}

int main() {
	scanf("%d%d%d",&n,&m,&K) ;
	int x1 , y1 ;
	for(int i = 0 ; i < K ; i++) {
		scanf("%d%d",&x1,&y1) ;
		x1-- ; y1-- ;
		vis[x1*m+y1] = -1 ;
	}

	for(int i = 0 ; i < n ; i++) {
		for(int j = (i%2) ; j < m ; j+=2) if(vis[i*m+j] != -1){
			q[res] = i*m+j ;
			head[res] = -1;
			for(int k = 0 ; k < 4 ; k++) {
				int nx = i + dx[k] , ny = j + dy[k] ;
				if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue ;
				if(vis[nx*m+ny] == -1) continue ;
				add(res, nx*m+ny) ;
			}
			res++ ;
		}
	}
	int ans = 0 ;
	for(int i = 1 ; i < res ; i++){
		T = i ;
		if(find(i)) ans++ ;
	}
	printf("%d",ans) ;
	return 0 ;
}