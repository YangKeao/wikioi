#include <iostream>
#include <string>
#include <queue>
using namespace std;
string a;
string end="123456780";
struct YKA{
	int g,h,zero;
	string content;
	YKA(){}
	YKA(int g,int h,string content,int zero):g(g),h(h),content(content),zero(zero){}
	bool operator < (const YKA &a) const{
		return g+h>a.g+a.h;
	}
};
priority_queue<YKA> que;
int GetH(string hh){
	int ss=0;
	for(int i=1;i<=9;i++){
		if(hh[i-1]-i<0)
			ss-=hh[i-1]-48-i;
		else ss+=hh[i-1]-48-i;
	}
	return ss;
}
int a_star(string a,int zero){
	que.push(YKA(1,GetH(a),a,zero));
	while(!que.empty()){
		YKA q=que.top();
		que.pop();
		int zero=q.zero;
		string str=q.content;
		if(str==end){
			return q.g;
		}
		int x=zero%3;
		int y=(zero-zero%3)/3;
		if(x>0){
			string tt=str;
			tt[zero]=tt[zero-1];
			tt[zero-1]=0;
			que.push(YKA(q.g+1,GetH(tt),tt,zero-1));
		}
		if(x<2){
			string tt=str;
			tt[zero]=tt[zero+1];
			tt[zero+1]=0;
			que.push(YKA(q.g+1,GetH(tt),tt,zero+1));
		}
		if(y>0){
			string tt=str;
			tt[zero]=tt[zero-3];
			tt[zero-3]=0;
			que.push(YKA(q.g+1,GetH(tt),tt,zero-3));
		}
		if(y<3){
			string tt=str;
			tt[zero]=tt[zero+3];
			tt[zero+3]=0;
			que.push(YKA(q.g+1,GetH(tt),tt,zero+3));
		}
	}
}
int main(){
	cin>>a;
	for(int i=0;i<=8;i++)
		if(a[i]=='0'){
			cout<<i;
			cout<<a_star(a,i);
		}
	return 0;
}