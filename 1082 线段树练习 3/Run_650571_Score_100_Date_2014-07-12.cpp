#include <stdio.h>
#include <iostream>
#include<ctype.h>
using namespace std;


inline long long readint()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	long long x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

long long buf[10];

inline void writeint(long long x)
{
	long long p=0;
	if(x==0)p++;
	else while(x)
	{
		buf[p++]=x%10;
		x/=10;
	}
	for(long long i=p-1;i>=0;i--)putchar('0'+buf[i]);
	return;
}



struct Node
{
	long long left;
	long long right;
	long long delta;
	long long sum;
	Node *lc;
	Node *rc;
};
 
void build(Node *cur,long long l,long long r){
	cur->left=l;
	cur->right=r;
	cur->sum=0;
	if(l+1<r){
		cur->lc = new Node;
		cur->rc = new Node;
		build(cur->lc,l,(l+r)/2);
		build(cur->rc,(l+r)/2,r);
	}
	else cur->lc = cur->rc = NULL;
}
void update(Node *cur){
	cur->lc->sum+=cur->delta*(cur->lc->right - cur->lc->left);
	cur->rc->sum+=cur->delta*(cur->rc->right - cur->rc->left);
	cur->lc->delta+=cur->delta;
	cur->rc->delta+=cur->delta;
	cur->delta=0;
}
void change(Node *cur,long long l,long long r,long long delta){
	if(l<=cur->left&&r>=cur->right){
		cur->sum+=delta*(cur->right - cur->left);
		cur->delta+=delta;
	}
	else{
		if(cur->delta!=0) update(cur);
		if(l<(cur->left+cur->right)/2) change(cur->lc,l,r,delta);
		if(r>(cur->left+cur->right)/2) change(cur->rc,l,r,delta);
		cur->sum=cur->lc->sum+cur->rc->sum;
	}
}
long long query(Node *cur,long long l,long long r){
	if(l<=cur->left&&r>=cur->right)
		return cur->sum;
	else{
		if(cur->delta!=0)
			update(cur);
		long long ans=0;
		long long t=(cur->left+cur->right)/2;
		if(l<t) ans+=query(cur->lc,l,r);
		if(r>t) ans+=query(cur->rc,l,r);
		return ans;
	}
}
long long n,g,m;
long long a,b,c,d;
int main(){
	Node *cur=new Node;
	n=readint();
	build(cur,1,n+1);
	for(long long i=1;i<=n;i++){
		g=readint();
		change(cur,i,i+1,g);
	}
	m=readint();
	for(long long i=1;i<=m;i++){
		a=readint();
		if(a==1){
			b=readint();
			c=readint();
			d=readint();
			change(cur,b,c+1,d);
		}
		else{
			b=readint();
			c=readint();
			writeint(query(cur,b,c+1));
			putchar( '\n' );
		}
	}
	return 0;
}