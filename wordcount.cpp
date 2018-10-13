#include<iostream>
using namespace std;
int main()
{
	int i=0,count[256]={0};
	char *str=new char();
	char ch;
	cin>>str;
	while(str[i]!='\0')
	{
		ch=str[i];
		count[ch]++;
		i++;
		cout<<ch<<count[ch]<<" ";
	}
	return 0;
}
