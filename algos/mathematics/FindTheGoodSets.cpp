//Application of the sieve
#include<bits/stdc++.h>
using namespace std;
#define fact 1000000007
#define ll long long int
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		
		int *present =new  int[1000000];
        cin>>n;
        for(int i=0;i<n;i++)
        {int a;
        	cin>>a;
        	present[a]++;
        }
        for(int i=2;i<=1000000;i++)
        if(present[i]>0)
        {
        	for(int k=2;k*i<=1000000;k++)
        		if(present[i*k]>0)
        			present[i*k]=(present[i*k]%fact+present[i]%fact)%fact;

        }
        
        int count=0;
        for(int i=1;i<=1000000;i++)
        	count=(count%fact+present[i]%fact)%fact;
        cout<<count<<endl;
        


		
    }
  return 0;
}