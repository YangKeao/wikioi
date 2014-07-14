#include <iostream>
#include <string>
#include <map>
using namespace std;
int a,b,c;
string t,g;
map<string,string> father;
string getfather(string a){
	if(father[a]==a) return a;
	else father[a]=getfather(father[a]);
	return father[a];
}
void bin(string t,string g){
	string ft=getfather(t);
	string fg=getfather(g);
	if(ft!=fg) father[ft]=fg;
}
int main(){
	cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
		cin>>t;
        father[t]=t;
	}
	for(int i=1;i<=b;i++){
		cin>>t>>g;
		bin(t,g);
	}
	for(int i=1;i<=c;i++){
		cin>>t>>g;
		if(getfather(t)==getfather(g)) cout<<"safe"<<endl;
		else cout<<"cc cry"<<endl;
	}
	return 0;
}