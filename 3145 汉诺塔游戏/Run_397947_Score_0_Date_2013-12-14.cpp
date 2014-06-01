#include <iostream>
#include <math.h>
char ta[3];
int n;
using namespace std;
void move(int a,int b,int c){
     cout << a<<" from "<<ta[b]<<" to "<<ta[c]<<endl;
}
void han(int k,int s,int m,int e){
     if(k!=1) han(k-1,s,e,m);
     move(k,s,e);
     if(k!=1) han(k-1,m,s,e);
}
int main(){
    ta[1]='A';
    ta[2]='B';
    ta[3]='C';
    cin >> n;
    cout<<pow(2,n)-1;
    han(n,1,2,3);
    
    return 0;
}
