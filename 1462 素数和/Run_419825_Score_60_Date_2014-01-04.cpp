#include <iostream>
using namespace std;
int main(){
	int a,b,tot=0,ifs=0,t;
    cin>>a>>b;
    if (a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    for(int i=a+1;i<b;i++)
    {
    	for(int j=2;j<i;j++)
        	if(i%j==0) ifs=1;
        if(ifs==0) tot=tot+i;
        ifs=0;
    }
    cout<<tot;
    return 0;
}