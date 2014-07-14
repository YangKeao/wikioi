#include<iostream>
#include<algorithm>
using namespace std;
struct xd
{
int l;
int r;       
};
xd a[1000]; 
int comp(const xd &x,const xd &y)
{
    if(x.l<y.l)return 1;else return 0;
}
int min(const int &a,const int &b)
{
    if(a<b)return a;else return b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            int q,w;
            cin>>q>>w;
            if(q>w) {a[i].r=w;a[i].l=q;}
            else {a[i].l=q;a[i].r=w;}
    }
    sort(a+1,a+n+1,comp);
    int y=a[0].r;
    int num=1;
    for(int i=2;i<=n;i++)
     {
          if(y<=a[i].l)
          {num++;y=a[i].r;}
          else
          y=min(y,a[i].r);
     }  
     cout<<num; 
    return 0;
}
