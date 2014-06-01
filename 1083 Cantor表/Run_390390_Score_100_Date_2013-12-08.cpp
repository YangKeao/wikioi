#include<iostream>
using namespace std;
int main()
{
      int i,n,k=0,t,a,b;
      cin>>n;
      for(i=0;i<n;i++)
      {
          t=n-i;
	  n=n-i;
	  k=i+1;
      }
      if(k%2!=0) {
	a=k-(t-1);
	b=t;
      }
      else {
          a=t;
	  b=k-(t-1);
      }
      cout<<a<<"/"<<b;
      return 0;
}