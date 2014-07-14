#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int  chu[200];
stack<int> ting;
int n,num=1;
int q=1;
char t,g;
int main(){
    cin>>n;
    t=getchar();
    for(int i=1;i<=n;i++)
    {
    	t=getchar();
        if(t=='A'){
            chu[q]=num;
            num++;
            q++;
        }
        else if(t=='B'&&ting.size()<5)
        {
            ting.push(num);
            num++;
        }
        else if(t=='B'&&ting.size()>=5) 
        {
        	cout<<"No";
            return 0;
        }
        else if(t=='C'&&ting.size()!=0)
        {
            chu[q]=ting.top();
            ting.pop();
            q++;
        }
        else if(t=='C'&&ting.size()==0)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<q;i++) cout<<chu[i]<<endl;
	return 0;
}