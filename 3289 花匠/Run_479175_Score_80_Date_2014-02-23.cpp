#include <iostream>
using namespace std;
int n,h,all=0,a,b;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i==1) {all++;cin>>a;}
        if(i==2) {all++;cin>>b;}
        if(i>2) {
            int x;
        	cin>>x;
            if((x>b&&a>b)||(x<b&&a<b)) all++;
            a=b;
            b=x;
        }
    }
    cout<<all;
	return 0;
}