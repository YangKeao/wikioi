#include <iostream>
#include<string>
#include<string.h>
using namespace std;
string s1,s2;
int a[600];
int b[600];
int c[600];
int main(){
    int f0=0,ff=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    for(int i=1;i<=m;i++)a[i]=s1[m-i]-48;     
    for(int i=1;i<=n;i++)b[i]=s2[n-i]-48;
    
    if(m<n) m=n;
    if(c[m+1]!=0) m++;
    for(int i=m;i>=1;i--)
    {
            if(a[i]>b[i]) {ff=1;break;}
            else if(a[i]==b[i]) continue;
            else if(a[i]<b[i]) break;
    }
    if(ff==1)
    {    
        for(int i=1;i<600;i++)c[i]=a[i]-b[i];
         for(int i=1;i<m;i++)
         {
                    if(c[i]>=0) continue;
                    else if(c[i]<0&&(c[i+1]-1)==0&&i==m-1) ;
                    else if(c[i]<0) {c[i+1]--;c[i]=c[i]+10;}
         }
        for(int i=m;i>=1;i--)
    	{
                if(f0==0&&c[i]==0) {continue;f0=1;}
                else if(f0=1)cout<<c[i];
    	}
    }
    else if(ff==0) {
         for(int i=1;i<600;i++)c[i]=b[i]-a[i];
		  for(int i=1;i<m;i++)
         {
                    if(c[i]>=0) continue;
                    else if(c[i]<0&&(c[i+1]-1)==0&&i==m-1) ;
                    else if(c[i]<0) {c[i+1]--;c[i]=c[i]+10;}
         }
         cout << "-";
        for(int i=m;i>=1;i--)
    	{
                if(f0==0&&c[i]==0) {continue;f0=1;}
                else if(f0=1)cout<<c[i];
    	}
    }
    return 0;
}