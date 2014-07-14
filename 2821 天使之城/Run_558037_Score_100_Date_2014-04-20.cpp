#include <iostream>
#include <stack>
using namespace std;
stack<int> che;
int n;
int num=1;
int k=1;
char t;
int chu[500];
char str[500];
int main(){
	cin>>n;
    cin>>str;
    for(int i=1;i<=n;i++){
    	t=str[i-1];
        if(t=='A') {
            chu[k]=num;
            k++;
            num++;
        }
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
                chu[k]=che.top();
                k++;
                che.pop();
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=k-2;i++)    
    {
        cout<<chu[i]<<endl;
    }
    cout<<chu[k-1];
	return 0;
}