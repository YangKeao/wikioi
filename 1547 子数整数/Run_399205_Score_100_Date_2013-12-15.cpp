#include <iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int i=10000;i<=30000;i++)
    {
            int x1=i/100;
            int x2=(i/10)%1000;
            int x3=i%1000;
            if(x1%k==0&&x2%k==0&&x3%k==0) cout<<i<<endl;
    }
    return 0;
}
