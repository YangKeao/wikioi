#include<iostream>
using namespace std;
int fbo(int a){
    if(a>=0) return 5;
    return fbo(a+1)+fbo(a+2)+1;
}
int main(){
    int n;
    cin>>n;
    cout<<fbo(n);
    return 0;
}
