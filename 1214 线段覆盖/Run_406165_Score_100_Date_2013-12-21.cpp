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
    int n,i;
     cin>>n;
     for(i=1;i<=n;i++)
     {
                      int x,y;
                      cin>>x>>y;
                      if(x<y){a[i].l=x;a[i].r=y;} else{a[i].l=y;a[i].r=x;};
     }
     sort(a+1,a+n+1,comp);
     int y=a[1].r;
     int num=1;
     for(i=2;i<=n;i++)
     {
          if(y<=a[i].l)
          {num++;y=a[i].r;}
          else
          y=min(y,a[i].r);
     }  
     cout<<num;    
     return 0;
}
