#include<iostream.h>
#include<conio.h>
void linear(int arr[],int size,int ele)
{
 int flag=0;
 for(int i=0;i<size;i++)
 {
  if(arr[i]==ele)
  {
   cout<<"Elemnt found\n";
   flag=1;
  }
 }
 if(flag==0)
 {
  cout<<"Element not found\n";
 }
}

void main()
{
 clrscr();
 int size=10,ele=5;
 cout<<"Enter Size Of Array You Want To Enter(max.10):";
 cin>>size;
 int arr[10];
 cout<<"Enter Your Array:";
 for(int i=0;i<size;i++)
 {
  cin>>arr[i];
 }
 cout<<"\n Enter Element Need To Searched:";
 cin>>ele;
 linear(arr,size,ele);
 getch();
}

