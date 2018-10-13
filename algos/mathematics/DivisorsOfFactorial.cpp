#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fact 10000000007
ll count(ll n,ll i)
{   
	ll res=i;
	ll count=0;
	while(n/res>0)
	{
		count+=n/res;
        res=res*i;
	}
	return count;
}
int main()
{   
	vector<bool>a(50005);
	for(int i=4;i<=50000;i+=2)
		a[i]=true;
	for(int i=3;i<=50000;i+=2)
	{
		for(int j=3;j*i<=50000;j+=2)
		a[i*j]=true;

	}
	int test;
	cin>>test;
	while(test--)
   {ll res=1;
	
    int n;
    cin>>n;
	for(int i=2;i<=n;i++)
	if(!a[i])
	{
	    ll t=count(n,i);
	    
	    res=(res%fact*(t+1)%fact)%fact;
	}
	
	cout<<res<<endl;
}


    return 0;
}