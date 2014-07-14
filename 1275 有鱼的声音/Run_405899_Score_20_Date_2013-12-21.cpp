#include <iostream>
int a[6];
using namespace std;
int main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    if(a[1]>a[2]>a[3]>a[4]) cout<<"Fish Diving";
    else if(a[1]<a[2]<a[3]<a[4]) cout<<"Fish Rising";
    else if(a[1]==a[2]==a[3]==a[4]) cout<<"Fish At Constant Depth";
    else cout<<"No Fish";
    return 0;
}
