#include <iostream>
using namespace std;
int n,a,b,all,x,ok=5;
int main(){
    cin>>n;
    all=1;
    cin>>a;
    for(int i=2;i<=n;i++)
    {
            cin>>x;
            if(x>a&&ok!=1) {ok=1;all++;}
            if(x<a&&ok!=0) {ok=0;all++;}
            a=x;
    }
    cout<<all;
    return 0;
}
