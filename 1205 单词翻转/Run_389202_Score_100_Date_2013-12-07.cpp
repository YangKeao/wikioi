#include <iostream>
#include <string.h>
using namespace std;
char a[1000][1000];
int main(){
    int i=0,j=0;
    while(cin>>a[++i]);
    for(j=i-1;j>=1;j--) cout<<a[j]<<" ";
    return 0;
}
