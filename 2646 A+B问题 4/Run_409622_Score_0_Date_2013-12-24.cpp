#include <iostream>
#include <string.h>
int a,b;
int fm,fz;
char m[200],n[200];
void yf(){
	for(int i=1;i<=fz;i++)
        if(fm%i==0&&fz%i==0) {fm=fm/i;fz=fz/i;}
}
using namespace std;
int main(){
    int a1=0,a2=0,b1=0,b2=0;
	cin>>a>>b;
    cin>>m>>n;
    int i=0;
    while(m[i]!=47)
    {
    	a1=a1*10+(m[i]-48);
        i++;
    }
    i++;
    while(i<=strlen(m)-1)
    {
    	a2=a2*10+(m[i]-48);
        i++;
    }
    i=0;
    while(n[i]!=47)
    {
    	b1=b1*10+(n[i]-48);
        i++;
    }
    i++;
    while(i<=strlen(n)-1)
    {
    	b2=b2*10+(n[i]-48);
        i++;
    }
    i=0;
    fm=a2*b2;
    fz=a1*b2+a2*b1;
    while(fz>fm)
    {
    	fz=fz-fm;
        i++; 
    }
    if(i!=0)
    	cout<<i<<"+";
    yf();
    cout<<fz<<"/"<<fm;
    return 0;
}