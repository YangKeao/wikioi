#include <iostream>
char s[100];
using namespace std;
int main(){
    int n,m,save,num=0;
    cin>>n>>m;
    while(n!=0)
    {
                  s[num]=n%m;
                  num++;
                  n=n/m;
    }
    if(m<10)
             for(int i=num-1;i>=0;i--) cout<<int(s[i]);
    if(m>=10)
             for(int i=num-1;i>=0;i--) 
                     {
                                       if(int(s[i])<10)
                                            cout<<int(s[i]);
                                       else{
                                            s[i]=s[i]+55;     
                                            cout<<s[i];
                                       }
                     }
    return 0;
}
