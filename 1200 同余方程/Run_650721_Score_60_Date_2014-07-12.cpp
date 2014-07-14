#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;
long long a,b,m,l;
inline long long readint()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	long long x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
long long buf[20];
inline void writeint(long long x)
{
	long long p=0;
	if(x==0)p++;
	else while(x)
	{
		buf[p++]=x%10;
		x/=10;
	}
	for(long long i=p-1;i>=0;i--)putchar('0'+buf[i]);
	return;
}
int main(){
	a=readint();
	b=readint();
	a%=b;
	l=1%b;
	for(long long i=1;;i++){
		if((a*i)%b==l) {
			writeint(i);
			break;
		}
	}
	return 0;
}