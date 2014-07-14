#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int t,g;
int father[30000];
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
zuis zui[50002];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>zui[i].a>>zui[i].b>>zui[i].q;
	}
    for(int i=1;i<=n;i++) father[i]=i;
	sort(zui,zui+m+1,cmp);
    for(int i=0;i<=m-1;i++){
        t=zui[i].a;
        g=zui[i].b;
        if(getfather(t)==getfather(g)) {cout<<zui[i].q;return 0;}
        else{
        	bin(t,g);
            bin(g,t);
        }
    }
	for(int i=0;i<=m-1;i++){
		cout<<zui[i].q<<endl;
	}
	return 0;
}
