#include <iostream>
#include <string.h>
using namespace std;
int ifAM[1000];
int ifAk[1000];
char M[1000];
char k[200];
char C[1000];
int main(){
	cin>>k>>M;
	int klong=strlen(k);
	int Mlong=strlen(M);
	Mlong--;
	for(int i=0;i<=Mlong;i++)
	{
            if(M[i]>=65&&M[i]<=90) ifAM[i]=1;
            if(M[i]>=97&&M[i]<=122) ifAM[i]=0;
    }
    for(int i=0;i<=klong;i++)
	{
            if(k[i]>=65&&k[i]<=90) k[i]=k[i]+32;
    }
    for(int i=0;i<=Mlong;i++)
    {
            if(ifAM[i]==1) 
            {
                                         C[i]=M[i]-k[i%klong]+32+65;
                                         if(C[i]<65) C[i]=C[i]+26;
            }
            else if(ifAM[i]==0) 
            {
                                         C[i]=M[i]-k[i%klong]+97;
                                         if(C[i]<97) C[i]=C[i]+26;
            }
    }
    for(int i=0;i<=Mlong;i++)
            cout<<C[i];
	return 0;
}
