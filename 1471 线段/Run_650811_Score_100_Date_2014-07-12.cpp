#include <cstdio>
#include <ctype.h>
inline int readint()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int buf[10];

inline void writeint(int x)
{
	int p=0;
	if(x==0)p++;
	else while(x)
	{
		buf[p++]=x%10;
		x/=10;
	}
	for(int i=p-1;i>=0;i--)putchar('0'+buf[i]);
	return;
}


int n,m,t,g;
int s[50010];
int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		t=readint();
		g=readint();
		for(int j=t;j<=g;j++){
			s[j]++;
		}
	}
	m=readint();
	for(int i=1;i<=m;i++){
		t=readint();
		writeint(s[t]);
		putchar('\n');
	}
	return 0;
}