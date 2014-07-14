#include <iostream>
using namespace std;
int a,b,c;
int t,g;
int father[6000];
int getfather(int a){
	if(father[a]==a) return a;
	else father[a]=getfather(father[a]);
	return father[a];
}
void bin(int t,int g){
	int ft=getfather(t);
	int fg=getfather(g);
	father[ft]=father[fg];
}

int main(){
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
		father[i]=i;
	for(int i=1;i<=b;i++){
		cin>>t>>g;
		if(father[g]==g)
			father[g]=t;
		else bin(t,g);
	}
	for(int i=1;i<=c;i++){
		cin>>t>>g;
		if(getfather(t)==getfather(g)) cout<<"YES"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
