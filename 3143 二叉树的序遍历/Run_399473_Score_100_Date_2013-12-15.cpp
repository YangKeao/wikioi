#include <iostream>
int n;
using namespace std;
int l[20],r[20];
void qian(int num){
     cout<<num<<" ";
     if(l[num]!=0) qian(l[num]);
     if(r[num]!=0)qian(r[num]);
     }
void zhong(int num){
     if(l[num]!=0) zhong(l[num]);
     cout<<num<<" ";
     if(r[num]!=0)zhong(r[num]);
}
void hou(int num){
     if(l[num]!=0) hou(l[num]);
     if(r[num]!=0) hou(r[num]);
     cout<<num<<" ";
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    qian(1);
    cout<<endl;
    zhong(1);
    cout<<endl;
    hou(1);
    return 0;
}
