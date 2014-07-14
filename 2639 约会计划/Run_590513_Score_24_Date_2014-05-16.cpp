#include <iostream>
#include <string>
using namespace std;
int a,b,c;
int t,g;
int father[60000];
string gg,tt;
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
int re(string a){
	int sum;
	for(int i=0;i<=a.length()-1;i++)
	{
		sum=(sum+(a[i]-64)%5)*2;
	}
	return sum;
}
int main(){
	cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
		cin>>gg;
		t=re(gg);
        father[t]=t;
	}
	for(int i=1;i<=b;i++){
		cin>>tt>>gg;
		t=re(tt);
		g=re(gg);
		bin(t,g);
	}
	for(int i=1;i<=c;i++){
		cin>>tt>>gg;
		t=re(tt);
		g=re(gg);
		if(getfather(t)==getfather(g)) cout<<"safe"<<endl;
		else cout<<"cc cry"<<endl;
	}
	return 0;
}