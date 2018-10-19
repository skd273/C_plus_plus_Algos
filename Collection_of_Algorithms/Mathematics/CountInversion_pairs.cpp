#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long int getSeq(int a[],int st,int end)
{
	if(end==st)return 0;
	if(end-st==1){
		if(a[st]>a[end])
		{
			swap(a[st],a[end]);
			return 0;

		}
       else
		return a[st];
	}
    
	
	int mid=(st+end)/2;
	int b[end-st+1];
	int get1=getSeq(a,mid+1,end);
	int get2=getSeq(a,st,mid);
	int fir=st,sec=mid+1,cur=0,count=0;
	while(fir<=mid&&sec<=end)
	{
		if(a[fir]<a[sec])
		{
			b[cur++]=a[fir];
			count+=a[fir]*(end-sec+1);

			fir++;
		}
		else
		{  
			b[cur++]=a[sec];
			sec++;

		}
    }
	while(fir<=mid)
	{
		b[cur++]=a[fir];
		fir++;
	}
	while(sec<=end){
		b[cur++]=a[sec];
		sec++;
	}
	cur=0;
	for(int i=st;i<=end;i++)
		a[i]=b[cur++];
	return count+get1+get2;

}
long long solve(int a[],int n)
{
	return getSeq(a,0,n-1);
}
int main()
{
	int a[10001],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<solve(a,n);
}