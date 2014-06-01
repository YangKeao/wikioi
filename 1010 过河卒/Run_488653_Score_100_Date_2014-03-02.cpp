#include<iostream>
using namespace std;
int road[30][30],e[30][30];
int main()
{
    int m,n,x,y;
    cin>>m>>n>>x>>y;
    for(int i=0;i<=m;i++)
    {
         for(int j=0;j<=n;j++)
         {
              e[i][j]=1;
         }
    }
    road[0][0]=1;
    e[0][0]=0;
    e[x+1][y+2]=0;
    e[x+1][y-2]=0;
    e[x+2][y-1]=0;
    e[x+2][y+1]=0;
    e[x-1][y+2]=0;
    e[x-1][y-2]=0;
    e[x-2][y+1]=0;
    e[x-2][y-1]=0;
    e[x][y]=0;
    for(int i=0;i<=m;i++)
    {
         for(int j=0;j<=n;j++)
         {
              if(e[i][j]) road[i][j]=road[i-1][j]+road[i][j-1];
         }
    }
    cout<<road[m][n];
    return 0;
}