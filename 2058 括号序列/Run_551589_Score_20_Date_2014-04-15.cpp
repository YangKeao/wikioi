#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> q;
int n;
char t;
string m;
int ss;
char td(char a){
    if(a=='}') return '{';
    else if(a==')') return '(';
    else if(a=='>') return '<';
    else if(a==']') return '[';
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        for(int i=1;i<=m.length();i++)
        {
            t=m[i];
            if(t=='{'||t=='('||t=='<'||t=='[') q.push(t);
            else if(t=='}'||t==')'||t=='>'||t==']')
            {
                if(q.top()==char(t)) q.pop();
                else {cout<<"FALSE"<<endl;ss=1;break;}
            }
        }
        if(ss) {ss=0;}
        else cout<<"TRUE"<<endl;
    }
	return 0;
}
