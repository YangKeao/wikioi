#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int i,j,n,s=0,a[101];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
                     scanf("%d",&a [i] );
    for(i=1;i<=n;i++){
                      for(j=a [i] ;j!=1;){
                              if(j%2==0) j/=2,s++;
                              else if(j%2!=0) j=3*j+1,s++;
                      }
    printf("%d\n",s);
    s=0;
    }
return 0;
}
