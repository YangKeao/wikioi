#include <stdio.h>
#include <stdbool.h>
int n,m;
bool t[100005];
int g;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&g);
        t[g]=1;
    }
    for(int i=1;i<=m;i++){
    	scanf("%d",&g);
        if(t[g]) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
