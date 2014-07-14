#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
	int left;
	int right;
	int delta;
	int sum;
	Node *lc;
	Node *rc;
};

void build(Node *cur,int l,int r){
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
void change(Node *cur,int l,int r,int delta){
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
int query(Node *cur,int l,int r){
	if(l<=cur->left&&r>=cur->right)
		return cur->sum;
	else{
		if(cur->delta!=0)
			update(cur);
		int ans=0;
		int t=(cur->left+cur->right)/2;
		if(l<t) ans+=query(cur->lc,l,r);
		if(r>t) ans+=query(cur->rc,l,r);
		return ans;
	}
}
int n,g,m;
int a,b,c,d;
int main(){
	Node *cur=new Node;
	scanf("%d",&n);
	build(cur,1,n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&g);
		change(cur,i,i+1,g);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a);
		if(a==1){
			scanf("%d%d%d",&b,&c,&d);
			change(cur,b,c+1,d);
		}
		else{
			scanf("%d%d",&b,&c);
			printf("%d\n",query(cur,b,c+1));
		}
	}
	return 0;
}