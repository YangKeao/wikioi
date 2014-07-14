#include <iostream>
using namespace std;
int f[20000],x,n,m,t,g;
int find(int a){
	if(f[a]!=a) f[a]=find(f[a]);
    return f[a];
}
void check(int a,int b){
    if(find(a)==find(b)) {
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }
}
void bin(int a,int b){
	f[find(a)]==find(b);
}
int main(){
	cin>>x>>n>>m;
    for(int i=1;i<=x;i++) f[i]=i;
    for(int i=1;i<=n;i++) {
    	cin>>t>>g;
        bin(t,g);
    }
    for(int i=1;i<=m;i++) {
        cin>>t>>g;
        check(t,g);
    }
    return 0;
}