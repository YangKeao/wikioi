#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
using namespace std;
bool k=0;
string a,b;
string t,g;
multimap<string, string> change;
multimap<string,string>::iterator  run;
struct gobfs
{
	string a;
	int num;
	bool operator < (const gobfs &a) const{
		return a.num<num;
	}
};
priority_queue<gobfs> q;
int bfs(){
	gobfs z;
	gobfs tt;
	z.num=1;
	z.a=a;
	q.push(z);
	while(!q.empty()){
		z=q.top();
		q.pop();
		if(z.num>10) break;
		if(z.a==b) return z.num;
		for (run=change.begin();run!=change.end();run++){
			tt.num=z.num+1;
			string t=(*run).second;
			string g=(*run).first;
			tt.a=z.a;
			if(tt.a.find(g)!=string::npos){
				tt.a.replace(tt.a.find(g),tt.a.find(g)+g.length(),t);
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