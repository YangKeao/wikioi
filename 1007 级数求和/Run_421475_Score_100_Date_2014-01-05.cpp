#include<iostream>
using namespace std;

int main()
{
    int k,n=1;
    double Sn = 1;
    cin>>k;
    while (Sn<=k)
    {
    	n++;
    	Sn = Sn + 1.0/n;
    }
    cout<<n;
    return 0;
}