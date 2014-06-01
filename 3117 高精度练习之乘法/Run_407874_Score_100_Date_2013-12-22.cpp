#include <iostream>
#include <string.h>
using namespace std;
int main()  
{  
    char s1[555],s2[555],temp[555];  
    int m,n;  
    int a[555]={0},b[555]={0},c[1111]={0};  
    cin>>s1>>s2;
    if(strlen(s1)<strlen(s2))  
    {  
        strcpy(temp,s1);  
        strcpy(s1,s2);  
        strcpy(s2,temp);  
    }  
    m =strlen(s1);  
    for(int i=0;i<=m -1;i++)  
        a[i]=s1[m -1 -i]-'0';  
    n=strlen(s2);  
    for(int i=0;i<=n -1;i++)  
        b[i]=s2[n -1 -i]-'0';  
    for(int i=0;i<n;i++)  
        for(int j=0;j<m;j++)  
            c[i+j]+=a[j]*b[i];  
    for(int i=0;i<2*m;i++)  
        if(c[i]>=10)  
        {  
            c[i+1]+=c[i]/10;  
            c[i]%=10;  
        }  
    int longs=2*m;  
    while(c[longs]==0)  longs--;  
    if(longs<0)  cout<<0;
    else      
    {  
        for(int i=longs;i>=0;i--)  
            cout<<c[i];
    }  
    return 0;  
}  
