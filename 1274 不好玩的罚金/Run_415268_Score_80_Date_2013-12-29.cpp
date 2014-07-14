#include <iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the speed limit: ";
    cin>>n;
    cout<<"Enter the recorded speed of the car: ";
    cin>>m;
    int k=m-n;
    if(k>=1&&k<=20) cout<<"You are speeding and your fine is $ 100";
    if(k>20&&k<31) cout<<"You are speeding and your fine is $ 100";
    if(k>=32) cout<<"You are speeding and your fine is $ 500";
    if(k<=0) cout<<"Congratulations, you are within the speed limit";
    return 0;
}
