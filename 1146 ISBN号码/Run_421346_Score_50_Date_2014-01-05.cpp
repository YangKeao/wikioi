#include <iostream>
#include <string>
using namespace std;
string isbn;
int j=0;
int main(){
	cin>>isbn;
    int sum=0;
    for(int i=0;i<=(isbn.size()-3);i++)
    {
        if(isbn[i]=='-') continue;
    	sum=sum+(isbn[i]-'0')*(j+1);
        j++;
    }
    int r=sum%11;
    if(r==isbn[isbn.size()-1]-'0')
    	cout<<"Right";
    else
    {for(int i=0;i<=(isbn.size()-2);i++)
        	cout<<isbn[i];
        cout<<r;}
    return 0;
}