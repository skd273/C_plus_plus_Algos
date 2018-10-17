#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll raisepower(ll a,ll b,ll p)
{ll res=1;
	a%=p;
	while(b>0)
	{
		if(b%2!=0)res=(res%p*a%p)%p;
		b/=2;
		a=(a%p*a%p)%p;
	}
	return res%p;

}
ll moduloinverse(ll a,ll p)
{
return raisepower(a,p-2,p);

} 
ll nfactmodulom(ll n,ll p)
{if(p<=n)return 0;  
 ll res=1;
	n++;
	while(n!=p)
	{
       res=(res%p*moduloinverse(n,p)%p)%p;
		n++;
	}
	return p-res;

}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		cout<<nfactmodulom(n,m)<<endl;
	}

}