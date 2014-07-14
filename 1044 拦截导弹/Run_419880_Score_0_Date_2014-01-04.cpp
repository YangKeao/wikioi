#include <iostream>
int h[20],num,z=0;
using namespace std;
int main(){
    int i=0;
    int max=0,q=0;
    while(cin>>h[i]) i++;
    i--;
    for(int k=0;k<=i;k++)
    {
        if(h[k]<h[k-1]) continue;
        for(int j=k+1;j<=i;j++)
        {
            if(h[j]<h[j-1]) num++;
            if(num>max) max=num;
        }
        num=0;
    }
    for(int k=0;k<=i;k++)
    {
        if(h[k]<h[k+1]) z++;
    }
    z++;
    cout<<max<<endl<<z;
    return 0;
}