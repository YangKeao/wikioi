#include <iostream>
#include <string>
using namespace std;
int main()
{
           int first=1;
           string s[300];
           int i=0;
           while(cin)
           {
                    cin>>s[i++];
                    if(cin.get()=='\n')
                    break;
           }
           for(int j=i-1;j>=0;j--)
           {
                   if(first) {first--;cout<<s[j];continue;}
                       cout<<" "<<s[j];
           }
           return 0;
}
