#include <iostream>
#include <string>
using namespace std;
string shi;
int k;
int b,i;
int main(){
	cin>>shi;
	while(shi[i]!='=')
	{
		if(shi[i+1]>='0'&&shi[i+1]<='9'&&shi[i]=='-')
			{shi[i+1]='0'-shi[i+1];break;}
		else if(shi[i]>=('0'-9)&&shi[i]<='9'&&(shi[i+1]>='a'||shi[i+1]<='z'))
		   	{k=k+(shi[i]-'0');break;}
		else if(shi[i]>=('0'-9)&&shi[i]<='9'&&(shi[i+1]<'a'||shi[i+1]>'z'))
			{b=b-(shi[i]-'0');break;}
		i++;
	}
	i++;
	while(i<shi.size())
	{
		if(shi[i+1]>='0'&&shi[i+1]<='9'&&shi[i]=='-')
			{shi[i+1]='0'-shi[i+1];break;}
		else if(shi[i]>=('0'-9)&&shi[i]<='9'&&(shi[i+1]>='a'||shi[i+1]<='z'))
		   	{k=k-(shi[i]-'0');break;}
		else if(shi[i]>=('0'-9)&&shi[i]<='9'&&(shi[i+1]<'a'||shi[i+1]>'z'))
			{b=b+(shi[i]-'0');break;}
		i++;
	}
	cout<<(b/k);
	return 0;
}