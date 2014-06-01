#include <iostream>
#include <stdlib.h>
int a[100010];
int comp ( const void *a , const void *b )
    { 
        return *(int *)a - *(int *)b; 
    }
using namespace std;
int main(){
    int tot;
    cin >> tot;
    for(int i=0;i<=tot-1;i++)
    {
            cin>>a[i];
    }
    qsort(a,tot,sizeof(int),comp);
    for(int j=0;j<=tot-1;j++)
    cout << a[j] << endl;
    return 0;
}
