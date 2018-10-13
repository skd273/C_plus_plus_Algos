#include<bits/stdc++.h>
using namespace std;
#define ll long long
void multiply(ll a[][2],ll b[][2])
{
	ll fir=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	ll sec=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	ll thir=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	ll four=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	a[0][0]=fir;
	a[0][1]=sec;
	a[1][0]=thir;
	a[1][1]=four;

}
void matrixexpo(ll matrix[][2],int power)
{ll res[2][2]={{1,1},{1,0}};
	while(power>0)
	{
		if(power%2!=0)
			multiply(matrix,res);
		power/=2;
		multiply(res,res);

	}

}

int main()
{
	ll source[2][2]={{1,0},{0,1}};
    
    int n;
    cin>>n;
    matrixexpo(source,n-1);
    cout<<source[1][0]+source[1][1];



}