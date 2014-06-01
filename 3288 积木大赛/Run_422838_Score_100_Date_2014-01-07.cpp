#include <iostream>
using namespace std;
int ds[100000];
int main(){
	int n;
    cin>>n;
    ds[0]=0;
    for(int i=1;i<=n;i++)
    	cin>>ds[i];
    int tot=0;
    for(int i=1;i<=n;i++)
    	if(ds[i]>ds[i-1]) tot=tot+ds[i]-ds[i-1];
    cout<<tot;
    return 0;
}