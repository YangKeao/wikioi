#include <iostream>
#include <algorithm>
using namespace std;
int n,father[1000],sum;
struct Node
{
	int u,v,c;
}node[1000];
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
bool query(int u,int v){
	if(getfather(u)==getfather(v)) return 1;
	else return 0;
}
bool cmp(Node a,Node b){
	return a.c<b.c;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) father[i]=i;
	int t=1;
	for(int y=1;y<=n;y++)
	for(int x=1;x<=n;x++){
		node[t].u=y;
		node[t].v=x;
		cin>>node[t].c;
		t++;
	}
	sort(node+1,node+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		if(!query(node[i].u,node[i].v)){
			bin(node[i].u,node[i].v);
			sum+=node[i].c;
		}
	}
	cout<<sum;
	return 0;
}