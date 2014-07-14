#include <iostream>
int f[41][41][41][41];
int P[5];
int A[400];
using namespace std;
int Max(int a,int b,int c,int d){
	int max=0;
    if(a>max) max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(d>max) max=d;
    return max;
}
int ni,nj,nk,nl;
int main(){
    int n,m,i,j,k,l;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    	cin>>A[i];
    for(i=1;i<=m;i++)
    {
    	int mk=0;
        cin>>mk;
        P[mk]++;
    }
    f[0][0][0][0]=A[1];
    for(i=0;i<=P[1];i++)
        for(j=0;j<=P[2];j++)
            for(k=0;k<=P[3];k++)
                for(l=0;l<=P[4];l++)
    			{
        		if(i==j&&j==k&&k==l&&l==0) continue;
    			if(i!=0) ni=f[i-1][j][k][l]+A[i+j*2+k*3+l*4+1];
                else ni=0;
                if(j!=0) nj=f[i][j-1][k][l]+A[i+j*2+k*3+l*4+1];
                else nj=0;
                if(k!=0) nk=f[i][j][k-1][l]+A[i+j*2+k*3+l*4+1];
                else nk=0;
                if(l!=0) nl=f[i][j][k][l-1]+A[i+j*2+k*3+l*4+1];
                else nl=0;
                f[i][j][k][l]=Max(ni,nj,nk,nl);
                }
    cout<<f[i-1][j-1][k-1][l-1];
	return 0;
}
