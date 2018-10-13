#include<iostream>
using namespace std;

void selection(int arr[],int n)
{

    int smallest,pos;
    for(int i=0;i<n;i++)
    {
smallest=i;
for(int j=i+1;j<n;j++)
{
if(arr[j]<arr[smallest])
{

    smallest=j;
}

}

int temp=arr[smallest];
arr[smallest]=arr[i];
arr[i]=temp;

    }



}
int main()
{


int n;
cin>>n;
int *arr;
arr=new int[n];


for(int i=0;i<n;i++)
{

    cin>>arr[i];
}

selection(arr,n);
for(int i=0;i<n;i++)
{

    cout<<arr[i]<<" ";
}
return 0;

}
