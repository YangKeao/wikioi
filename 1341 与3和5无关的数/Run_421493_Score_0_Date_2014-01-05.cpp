#include <iostream>
#include <string>
using namespace std;
int main(){
	int  n,tot;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
    	int a=i/100;
        int b=(i/10)%10;
        int c=i%10;
        if(c!=3&&c!=5&&b!=3&&b!=5&&a!=3&&a!=5&&i%5!=0&&i%3!=0)
        {
            tot=tot+i*i;
         	
        }
    }
    cout<<tot;
    return 0;
}