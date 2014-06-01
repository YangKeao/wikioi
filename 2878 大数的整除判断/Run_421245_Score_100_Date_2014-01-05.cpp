#include <iostream>
#include <string>
using namespace std;
string a,b;
int main(){
	cin>>a>>b;
    int la=a.size();
    int lb=b.size();
    if(a[la-1]=='0'||b[lb-1]=='0'||a[la-1]=='5'||b[lb-1]=='5') cout<<"Yes";
    else cout<<"No";
    return 0;
}