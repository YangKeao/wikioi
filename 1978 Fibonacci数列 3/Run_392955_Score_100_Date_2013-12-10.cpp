#include<iostream>
using namespace std;
int fbo(int a){
    if(a==1 || a==2) return 1;
    return fbo(a-1)+fbo(a-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fbo(n);
    return 0;
}
