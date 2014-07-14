#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	long long l;
	long long r;
	long long sum;
	long long add;
	node *lc;
	node *rc;
};
void build(node *cur,long long l,long long r){
	cur->l=l;
	cur->r=r;
	cur->sum=0;
	if (l+1<r){
		cur->lc=new node;
		cur->rc=new node;
		build(cur->lc,l,(l+r)/2);
		build(cur->rc,(l+r)/2,r);
	}
	else cur->lc=cur->rc=NULL;
}
void update(node *cur){
	cur->lc->sum+=cur->add*(cur->lc->r - cur->lc->l);
	cur->rc->sum+=cur->add*(cur->rc->r - cur->rc->l);
	cur->lc->add+=cur->add;
	cur->rc->add+=cur->add;
	cur->add=0;
}
void change(node *cur,long long l,long long r,long long add){
	if (l<=cur->l && cur->r<=r){
		cur->sum+=add*(cur->r - cur->l);
		cur->add+=add;
	}
	else {
		if (cur->add!=0) update(cur);
		if(l<(cur->l + cur->r)/2) change(cur->lc,l,r,add);
		if(r>(cur->l + cur->r)/2) change(cur->rc,l,r,add);
		cur->sum=cur->lc->sum + cur->rc->sum;
	}
}
long long query(node *cur,long long l,long long r){
	if (l<=cur->l && cur->r<=r)
		return cur->sum;
	else{
		if (cur->add!=0)
			update(cur);
		long long ans=0;
		if (l<(cur->l+cur->r)/2)
			ans+=query(cur->lc,l,r);
		if (r>(cur->l+cur->r)/2)
			ans+=query(cur->rc,l,r);
		return ans;
	}
}
int main(){
	long long n,q,i,a,b,c,d;
	node*cur;
	cur=new node;
	scanf(" %lld",&n);
	build(cur,1,n+1);
	for (i=1;i<=n;i++){
		scanf(" %lld",&a);
		change(cur,i,i+1,a);
	}
	scanf(" %lld",&q);
	for (i=1;i<=q;i++){
		scanf(" %lld",&a);
		if (a==1){
			scanf("%lld %lld %lld",&b,&c,&d);
			change(cur,b,c+1,d);
		}
		else{
			scanf("%lld %lld",&b,&c);
			printf("%lld\n",query(cur,b,c+1));
		}
	}
	return 0;
}