#include <iostream>
using namespace std;int n,a[6000];int f[6000];int t=1;int main(){cin>>n;for(int i=1;i<=n;i++)cin>>a[i];for(int i=n;i>0;i--){t=1;for(int j=n;j>i;j--)if(a[j]>=a[i]&&f[j]>=t) t=f[j]+1;f[i]=t;}t=1;for(int i=1;i<=n;i++)if(f[i]>t) t=f[i];cout<<t;return 0;}