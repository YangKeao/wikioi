#include <iostream>
using namespace std;
int n,a,b,all,x;
int main(){
    cin>>n;
    all=2;
    cin>>a>>b;
    for(int i=3;i<=n;i++)
    {
            cin>>x;
            if((x<b&&a<b)||(x>b&&a>b)) all++;
            b=x;
            a=b;
    }
    cout<<all;
    return 0;
}
