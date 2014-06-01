#include <iostream>
using namespace std;
int l[20],r[20],max1,max2,n;
int c[20];
void doit(int x,int t){
     c[t]++;
     if(c[t]>max2) max2=c[t];
     if(t>max1) max1=t;
     if(l[x]>0) doit(l[x],t+1);
     if(r[x]>0) doit(r[x],t+1);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    doit(1,1);
    cout<<max2<<" "<<max1<<endl;
    return 0;
}
