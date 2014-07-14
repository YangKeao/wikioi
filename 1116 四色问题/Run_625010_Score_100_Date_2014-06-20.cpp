#include <iostream>
using namespace std;
int n,ans;
int a[100][100];
int c[5];
int d[10];
int t,g;
void sou(int b){
	if(b>n) ans++;
	else{
		for(int i=1;i<=4;i++){
			int k=1;
			for(int j=1;j<=n;j++){
				if(a[b][j]&&d[j]==i){
					k=0;
					break;
				}
			}
			if(k){
				c[i]=1;
				d[b]=i;
				sou(b+1);
				c[i]=0;
				d[b]=0;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=4;i++) c[i]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		cin>>t;
		if(t) {
			a[i][j]=1;
		}
	}
	sou(1);
	cout<<ans;
	return 0;
}