#include <iostream>
int a[5];
using namespace std;
int main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    if(a[1]>a[2]>a[3]>a[4]) {cout<<"Fish Diving";return 0;}
    else if(a[1]<a[2]<a[3]<a[4]) {cout<<"Fish Rising";return 0;}
    else if(a[1]==a[2]==a[3]==a[4]) {cout<<"Fish At Constant Depth";return 0;}
    else {cout<<"No Fish";return 0;}
    return 0;
}
