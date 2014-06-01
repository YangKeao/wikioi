#include <iostream>
using namespace std;
int r[15];
int z[15];
int l[30];
int n,ans;
void dfs(int t){
	int i;
    if(t>n) {ans++;return;};
    for(i=1;i<=n;i++)
        if(z[i]==0&&l[i+t]==0&&r[i-t+n]==0){
            z[i]=1;l[i+t]=1;r[i-t+n]=1;
            dfs(t+1);
            z[i]=0;l[i+t]=0;r[i-t+n]=0;
        }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}