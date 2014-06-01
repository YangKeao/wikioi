#include <iostream>
int a[110][110];
using namespace std;
int main(){
    int n,num=1,sum=0;
    cin >> n;
    for(int i=1;i<=110;i++)
            for(int j=1;j<=110;j++)
                    a[i][j]=0;
    int x=n,y=n;
    num=n*n;
    a[x][y]=num--;
    while(num>=1){
            while(x>1&&a[x-1][y]==0){x--;a[x][y]=num--;}
            while(y>1&&a[x][y-1]==0){y--;a[x][y]=num--;}
            while(x<n&&a[x+1][y]==0){x++;a[x][y]=num--;}
            while(y<n&&a[x][y+1]==0){y++;a[x][y]=num--;}
    }
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=n;j++)
                    cout<<a[j][i]<<" ";
            cout<<endl;
}
    for(int i=1;i<=n;i++)
            sum=sum+a[i][i];
    for(int i=0;i<=n;i++)
            sum=sum+a[n-i][i+1];
    sum=sum-1;
    cout<<sum;
    
    return 0;
}
