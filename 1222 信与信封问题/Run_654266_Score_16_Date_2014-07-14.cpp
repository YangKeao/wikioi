#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 110
using namespace std;
int t,g;
struct NNN{
	bool unblieve[MAX];
	int sum;
}N[MAX];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		N[i].sum=n;
	}
	while(1){
		scanf("%d%d",&t,&g);
		if(t==0&&g==0) break;
		else{
			N[t].unblieve[g]=1;
			N[t].sum--;
		}
	}
	int k=1;
	for(int q=1;q<=2000;q++){
		for(int i=1;i<=n;i++){
			if(N[i].sum==1){
				k=0;
				for(int j=1;j<=n;j++){
					if(!N[i].unblieve[j]){
						printf("%d %d\n",i,j);
						for(int k=1;k<=n;k++){
							if(!N[k].unblieve[j]){
								N[k].unblieve[j]=1;
								N[k].sum--;
							}
						}
					}
				}
			}
		}
	}
	if(k) printf("none");
	return 0;
}