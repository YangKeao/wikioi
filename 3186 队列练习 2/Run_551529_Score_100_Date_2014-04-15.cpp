#include <iostream>
#include <queue>
using namespace std;
int n;
int t,g;
int main(){
    cin>>n;
    queue<int>dui;
    for(int i=1;i<=n;i++)
    {
    	cin>>t;
        if(t==1) {
        	cin>>g;
            dui.push(g);
        }
        else if(t==2&&(!dui.empty()))dui.pop();
        else if(t==2&&dui.empty()) {cout<<"impossible!";return 0;}
    }
    if(dui.empty()) cout<<"impossible!";
    else
    	cout<<dui.front();
	return 0;
}