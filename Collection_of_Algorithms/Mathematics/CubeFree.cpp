#include<bits/stdc++.h>
using namespace std;

int main(){
  // Write your code here
bool a[1000001];
 for(int i=2;i<=100;i++)
 if(!a[i])
 {
  int p=i*i*i;
  for(int j=1;j*p<=1000000;j++)
    a[p*j]=true;
 }
 int m=0;
map<int,int>b;
 for(int k=1;k<=1000000;k++)
 {
  if(a[k]==true)
    {b[k]=-1;
      m++;
    }
    else
  b[k]=k-m;
 }


int test;
scanf("%d",&test);
for(int i=1;i<=test;i++)
{int p;
  scanf("%d",&p);
 if(b[p]!=-1)
  
printf("Case %d: %d \n",i,b[p]);
  cout<<"Case "<<i<<": Not Cube Free\n";
 else printf("Case %d: Not Cube Free\n",i);
}
  
 
  return 0;
}