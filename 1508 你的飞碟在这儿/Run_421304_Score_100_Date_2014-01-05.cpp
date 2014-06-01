#include<iostream>
#include<cstring>
using namespace std;
char a[7],b[7];
int i,sum1=1,sum2=1;
int main(){
    cin>>a;
    cin>>b;
    for(i=0;i<strlen(a);i++)
    sum1*=a[i]-64;
    for(i=0;i<strlen(b);i++)
    sum2*=b[i]-64;
    if(sum1%47==sum2%47)cout<<"GO";
    else cout<<"STAY";
    return 0;
}