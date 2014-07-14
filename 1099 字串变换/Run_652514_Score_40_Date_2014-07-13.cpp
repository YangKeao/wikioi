#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
using namespace std;
bool k=0;
string a,b;
string t,g;
multimap<string,string> change;
map<string,bool> inq;
multimap<string,string>::iterator  run;
struct gobfs
{
	string a;
	int num;
	bool operator < (const gobfs &a) const{
		return a.num<num;
	}
};

int bfs(){
	priority_queue<gobfs> q;
	gobfs z;
	gobfs tt;
	z.num=0;
	z.a=a;
	q.push(z);
	inq[z.a]=1;
	while(!q.empty()){
		z=q.top();
		q.pop();
		inq[z.a]=0;
		if(z.num>10) return -1;
		if(z.a==b) return z.num;
		for (run=change.begin();run!=change.end();run++){
			tt.num=z.num+1;
			string t=(*run).second;
			string g=(*run).first;
			tt.a=z.a;
			if(tt.a.find(g)!=string::npos){
				tt.a.replace(tt.a.find(g),tt.a.find(g)+g.length(),t);
				//if(!inq[tt.a])
					q.push(tt);
			}
		}
	}
	return -1;
}

int main(){
	cin>>a>>b;
	while(cin>>t>>g){
		change.insert(pair<string, string>(t, g));
	}
	if(bfs()==-1) cout<<"NO ANSWER!";
	else
		cout<<bfs();
	return 0;
}