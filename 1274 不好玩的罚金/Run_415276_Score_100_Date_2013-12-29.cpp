#include <iostream>
using namespace std;
int main(){
 int p,q,h;
    cout<<"Enter the speed limit: ";//输入输出流
        cin>>p;
        cout<<"Enter the recorded speed of the car: ";//输入输出流
    cin>>q;
    h=q-p;
    if(h<1)cout<<"Congratulations, you are within the speed limit";//范围判断
    if(h>=1&&h<=20)cout<<"You are speeding and your fine is $ 100";//范围判断
    if(h>=21&&h<=30)cout<<"You are speeding and your fine is $ 270";//范围判断
    if(h>=31)cout<<"You are speeding and your fine is $ 500";//范围判断
    return 0;
}
