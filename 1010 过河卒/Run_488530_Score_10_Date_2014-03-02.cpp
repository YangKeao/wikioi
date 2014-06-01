#include <iostream>
using namespace std;
int n,m,x,y;
int ge[30][30];
int run(int x,int y){
	if(x==n&&y==m) return 1;
    if(ge[x][y]==1||x>n||y>m) return 0;
    return run(x+1,y)+run(x,y+1);
}
int main(){
	cin>>n>>m>>x>>y;
    ge[x][y]=1;
    ge[x-2][y-1]=1;
    ge[x-1][y-2]=1;
    ge[x+1][y-2]=1;
    ge[x+2][y-1]=1;
    ge[x+2][y+1]=1;
    ge[x+1][y+2]=1;
    ge[x-1][y+2]=1;
    ge[x-2][y-1]=1;
    cout<<run(0,0);
    return 0;
}
