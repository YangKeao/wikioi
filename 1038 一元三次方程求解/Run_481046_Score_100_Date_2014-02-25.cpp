#include <iostream>
#include <stdio.h>
using namespace std;
int f;
double a,b,c,d,q,k=0,jie;
int main(){
    cin>>a>>b>>c>>d;
    for(double i=-99.99;i<=100;i=i+0.01)
    {
        	jie=a*i*i*i+b*i*i+c*i+d;
            if(f==0&&jie>0)
            {
                printf("%.2f ",i);
                k++;
                f=1;
            }
        	else if(f==1&&jie<0)
            {
            	printf("%.2f ",i);
                k++;
                f=0;
            }
        	else if(jie==0)
            {
            	printf("%.2f ",i);
                k++;
                f=4;
            }
        	if(jie>0) f=1;
        	else if(jie<0) f=0;
    }
    return 0;
}
