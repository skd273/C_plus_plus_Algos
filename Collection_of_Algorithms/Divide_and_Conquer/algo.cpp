#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,key;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    int l=0,h=n-1;
    cout<<"Enter the element to be searched"<<endl;
    cin>>key;
    while(l<=h)
    {
        int mid=(l+h)/2;//overflow instead use mid=l+(h-l)/2;

        if(a[mid]==key)
        {
        cout<<"Found at index "<<mid<<endl;
        break;
        }
        else if(key<a[mid])
        h=mid-1;
        else
        l=mid+1;
    }
    if(l>h)
    cout<<" Element Not Found"<<endl;

}