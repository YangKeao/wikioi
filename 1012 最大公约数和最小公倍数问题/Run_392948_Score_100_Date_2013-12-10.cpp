#include <iostream>
using namespace std;

int gys(int a,int b)
{
	if(a%b==0) return b;
    gys(b,a%b);
}
int gbs(int a,int b)
{
	return a*b/gys(a,b);
}
int main(){
	int x,y,p,q,num=0;
    cin>>x>>y;
    for(p=x;p<=y;p=p+x)
        for(q=x;q<=y;q=q+x)
        if(gys(p,q)==x&&gbs(p,q)==y){num++;};
    
    cout<<num;
    return 0;
}