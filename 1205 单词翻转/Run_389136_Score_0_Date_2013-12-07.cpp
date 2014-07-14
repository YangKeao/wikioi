#include <stdio.h>
char s[100][100];
int main(){
    int i=0;
    while(scanf("%s",&s[i])==1)
    {
                           i++;
    }
    for(;i>=0;i--)
                  printf("%s ",s[i]);
    return 0;
}
