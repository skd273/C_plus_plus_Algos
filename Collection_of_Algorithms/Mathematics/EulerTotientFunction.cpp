#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int *Etotient=new int[1000000];

//initialize the array with corresponding index to differ primes
	for(int i=0;i<=1000000;i++)
		Etotient[i]=i;

//the factors of each prime is multiplied by prev*(1-1/factor)

	for(ll i=2;i<=1000000;i++)
		if(Etotient[i]==i)
		{int fact=Etotient[i];
			for(ll j=1;j*i<=1000000;j++)
				Etotient[i*j]=Etotient[i*j]-Etotient[i*j]/fact;

		}
		int test;
		cin>>test;
		while(test--)
		{
			int number;
			cin>>number;
			cout<<Etotient[number]<<endl;
		}
}