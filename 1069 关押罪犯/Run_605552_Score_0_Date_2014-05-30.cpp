#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int father[6000];
int getfather(int a){
	if(father[a]==a) return a;
	else father[a]=getfather(father[a]);
	return father[a];
}
void bin(int t,int g){
	int ft=getfather(t);
	int fg=getfather(g);
	if(ft!=fg) father[ft]=fg;
}
struct zuis{
	int a;
	int b;
	int q;
};
int cmp(zuis x,zuis y){
	return x.q>y.q;
}
zuis zui[500];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>zui[i].a>>zui[i].b>>zui[i].q;
	}
	sort(zui,zui+m+1,cmp);
	for(int i=0;i<=m-1;i++){
		cout<<zui[i].q<<endl;
	}
	return 0;
}