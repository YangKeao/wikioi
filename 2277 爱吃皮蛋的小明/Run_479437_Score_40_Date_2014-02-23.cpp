#include<iostream>
using namespace std;
int N;
long long sum;
long long run(long long sum)
{
     if(sum==1) return 1;
     else if(sum==2) return 2;
     else return run(sum-1)+run(sum-2);
}
int main()
{
    cin>>N;
    cout<<run(N);
    return 0;
}	
