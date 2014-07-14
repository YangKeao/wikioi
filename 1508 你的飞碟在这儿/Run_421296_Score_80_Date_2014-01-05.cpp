#include <iostream>
#include <string>
using namespace std;
string a,b;
int suma=1,sumb=1,la,lb;
int main(){
	cin>>a>>b;
    la=a.size();
    lb=b.size();
    for(int i=0;i<=la-1;i++)
        suma=suma*(a[i]-64);
    for(int i=0;i<=la-1;i++)
        sumb=sumb*(b[i]-64);
    if(suma%47==sumb%47) cout<<"GO";
    else cout<<"STAY";
    return 0;
}