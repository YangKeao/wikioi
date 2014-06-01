#include <iostream>
using namespace std;
int main(){
    int jia=0,a,b,c,c1;
    cin>>a>>b;
    c=a-b;
    c1=c;
    cout<<c1<<endl;
    if(c>=100){if(jia==1)cout<<"+";cout<<100<<"*"<<c/100;c=c%100;jia=1;}
    if(c>=50){if(jia==1)cout<<"+";cout<<50<<"*"<<c/50;c=c%50;jia=1;}
    if(c>=20){if(jia==1)cout<<"+";cout<<20<<"*"<<c/20;c=c%20;jia=1;}
    if(c>=10){if(jia==1)cout<<"+";cout<<10<<"*"<<c/10;c=c%10;jia=1;}
    if(c>=5){if(jia==1)cout<<"+";cout<<5<<"*"<<c/5;c=c%5;jia=1;}
    if(c>=1){if(jia==1)cout<<"+";cout<<1<<"*"<<c/1;c=c%1;jia=1;}
    return 0;
}