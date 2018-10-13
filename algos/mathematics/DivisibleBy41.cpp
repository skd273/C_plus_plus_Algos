#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{int a0,a1,c,n;
		cin>>a0>>a1>>c>>n;
		int res=10*a0+a1;
	
		for(int i=n-3;i>=0;i--)
		{
			int cur=(c*a1+a0)%10;
			res=(res*10+cur)%41;
			int temp=a1;
			a1=cur;
			a0=temp;
		}
		
		if(res==0||res%41==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
}