#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    int i,j,k,sum=0,m,l;
    char s[20];
    cin>>s>>m;
    k=strlen(s);
    j=k;
    for(i=0;i<j;i++,k--)
    {
        if(s[i]>='A') s[i]=s[i]-'A'+10;
        else s[i]-='0';
        sum=sum*m+s[i];    
    }
    cout<<sum;
    return 0;
}
