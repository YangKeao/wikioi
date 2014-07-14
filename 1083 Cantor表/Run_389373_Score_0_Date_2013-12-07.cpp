#include <iostream>
using namespace std;
int main(){
    int h=1,N,sum=0,k;
    cin >> N;
    for(int j=1;;j++) 
    {
        k=j;
        if(sum+j>=N) break;
        sum=sum+j;
    }
    int a=N-sum;
    cout <<a<<"/"<<k;
    return 0;
}
