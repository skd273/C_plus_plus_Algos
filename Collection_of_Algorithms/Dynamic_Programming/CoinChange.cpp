//Author:: ayushjain02

#include <bits/stdc++.h>
using namespace std;

int main(){
    //you can increase the no of denominations here.
    int den[5]={0,1,2,5,10};
    int value;
    cout<<"Enter the amount\n";
    cin>>value;
    int mem[5][value+1];
    mem[0][0]=0;
    for(int i=1;i<=4;i++)
        mem[i][0]=0;
    for(int i=1;i<=value;i++)
        mem[0][i]=value+1;
    for(int i=1;i<5;i++){
        for(int j=1;j<value+1;j++)
            mem[i][j]=min(1+mem[i][j-den[i]],mem[i-1][j]);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<value+1;j++)
            cout<<mem[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"Minimum no of coins required are: "<<mem[4][value];
    return 0;
}
