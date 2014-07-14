#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;
int m,n;
bool suu[110];
bool su(int a){
	bool k=1;
	for(int i=2;i<a;i++){
		if((a%i)==0) k=0;
	}
	return k;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		suu[i]=su(i);
	}
	int ans=0;
	for(int i=2;i<=m-n;i++){
		if(suu[i]&&suu[i+n]) {
			cout<<i<<" "<<i+n<<endl;
			ans++;
		}
	}
	cout<<"Total Is:"<<ans;
	return 0;
}