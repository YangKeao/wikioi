#include <iostream>
int h[20],num;
using namespace std;
int main(){
    int i=0;
    int max=0;
    while(cin>>h[i]) i++;
    i--;
    for(int k=0;k<=i;k++)
    {
        for(int j=k+1;j<=i;j++)
        {
            if(h[k]<h[k-1]) num++;
            else j=i;
            if(num>max) max=num;
            
        }
        num=0;
    }
    cout<<max;
    return 0;
}
