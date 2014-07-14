#include <iostream>
using namespace std;
int n,m,fen[360],p[5],f[50][50][50][50];
int t,ci,cj,ck,cq;
int domax(int a,int b,int c,int d){
	int max=0;
    if(a>max) max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(d>max) max=d;
    return max;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>fen[i];
    }
    for(int i=1;i<=m;i++)
    {
        int t=0;
   		cin>>t;
        p[t]++;
    }
    f[0][0][0][0]=fen[1];
    for(int i=0;i<=p[1];i++)
    for(int j=0;j<=p[2];j++)
    for(int k=0;k<=p[3];k++)
    for(int q=0;q<=p[4];q++)
    {
        if(i==0&&j==0&&k==0&&q==0) continue;
        if(i>0) ci=f[i-1][j][k][q]+fen[i+j*2+k*3+q*4+1];else ci=0;
        if(j>0) cj=f[i][j-1][k][q]+fen[i+j*2+k*3+q*4+1];else cj=0;
        if(k>0) ck=f[i][j][k-1][q]+fen[i+j*2+k*3+q*4+1];else ck=0;
        if(q>0) cq=f[i][j][k][q-1]+fen[i+j*2+k*3+q*4+1];else cq=0;
        f[i][j][k][q]=domax(ci,cj,ck,cq);
    }
    cout<<f[p[1]][p[2]][p[3]][p[4]];
	return 0;
}
