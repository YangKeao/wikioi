#include <iostream>
#include <stack>
using namespace std;
stack<int> che;
int n;
int num=1;
char t;
int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>t;
        if(t=='A') {cout<<num<<endl;num++;}
        if(t=='B'){
            if(che.size()==5) {cout<<"No";return 0;}
            else{
            	che.push(num);
                num++;
            }
        }
        if(t=='C'){
            if(che.empty()) {cout<<"No";return 0;}
            else{
            	cout<<che.top()<<endl;
                che.pop();
            }
        }
    }
	return 0;
}