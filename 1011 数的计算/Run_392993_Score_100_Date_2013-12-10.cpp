#include <iostream>
using namespace std;
int f(int n){
    int i,m=1;
    if(n==1)return 1;
    for(i=1;i<=n/2;i++)m+=f(i);
    return m; 
}
int main(){
    int n;
    cin >>n;
    cout << f(n);
    
    return 0;
}
