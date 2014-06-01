#include <iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    int m=0;
    for(int i=2;i<k;i++)
            if(k%i==0) m=1;
    if(m) cout<<"\\n";
    else cout<<"\\t";
    return 0;
}
