/*
* Program to find the lowest common subsequence between 2 strings
*/
#include<iostream>
#include<string.h>

using namespace std;

void LCS_length(char A[],char B[],int ,int);
void print_LCS(char A[],int ,int);
void shift(char A[],int);

int C[100][100];
char D[100][100];

int main()
{
	char A[100],B[100];
	int l1=0,l2=0;
	cout<<"\nEnter the first sequence=";                                             //enter the two sequence.
	gets(A);
	cout<<"\nEnter the second sequence=";
	gets(B);
	l1=strlen(A);                                                                  //find their length
	l2=strlen(B);
	shift(A,l1);
	shift(B,l2);
	if(l1==0 || l2==0)
	{
		cout<<"\nThe length of the LCS is zero(0).Ending program.";                //if any of the sequence has zero length then empty subsequence.
		return 0;
	}
	LCS_length(A,B,l1,l2);                                                         //find the length of LCS and assign directional values to char D[][]
	cout<<"\nThe LCS is:\n";
	print_LCS(A,l1,l2);
	cout<<"\nThe length of the LCS="<<C[l1][l2];
	return 0;
}

void LCS_length(char A[],char B[],int l1,int l2)
{
	int i,j;
	for(i=0;i<=l1;i++)                                                          //assign '0' to the first row and column as a breaking point for recursion ahead.
	{
		C[i][0]=0;
	}
	for(i=0;i<=l1;i++)
	{
		C[0][i]=0;
	}
	for(i=1;i<=l1;i++)
	{
		for(j=1;j<=l2;j++)
		{
			if(A[i]==B[j])                                //if l1,l2>0 and elements are equal
			{
				C[i][j]=C[i-1][j-1] + 1;                 //assign preceeding diagonal value
				D[i][j]='d';                             // move diagonally
			}
			else
			if(C[i-1][j]>=C[i][j-1])           //if l1,l2>0 and elements are not equal then choose the greater value out of the upper element and element on left
			{
				C[i][j]=C[i-1][j];
				D[i][j]='u';                           //go up
			}
			else
			{
				C[i][j]=C[i][j-1];
				D[i][j]='l';                          //go left
			}
		}
	}
}

void print_LCS(char A[],int i,int j)
{
	if(i==0 || j==0)                             //breaking point of recursion.
	return ;
	else
	if(D[i][j]=='d')                            //move diagonally
	{
		print_LCS(A,i-1,j-1);
		cout<<A[i];
	}
	else
	if(D[i][j]=='u')                           //move up
	{
		print_LCS(A,i-1,j);
	}
	else                                       //move left.
	{
		print_LCS(A,i,j-1);
	}
}

void shift(char A[],int s)
{
	int i;
	for(i=s;i>=0;i--)
	{
		A[i+1]=A[i];
	}
}