#include <iostream>
#include <string>
using namespace std;
int main()
{
           string sent[300];
           int i=0;
           while(cin)
           {
                    cin>>sent[i++];
                    if(cin.get()=='\n')
                    break;
           }
           for(int j=i-1;j>=0;j--)
           {
                       cout<<sent[j]<<" ";
           }
           cout<<endl;
           return 0;
}
