#include<iostream.h>
#include<conio.h>

void BUILD_MAXHEAP(int a[],int n);

void MAX_HEAPIFY(int a[],int n,int c);

void HEAP_SORT(int a[],int n);

int  main()
{
    int *a;
    int n,i;
    int hsize=n-1;
    clrscr();
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    a=new int[n];
    cout<<"Enter elements:"<<endl;
    for(i=0;i<n;i++)
	cin>>a[i];
	HEAP_SORT(a,n);
	cout<<"sorted array: "<<endl;
	for(i=0;i<n;i++)
	    cout<<"\t"<<a[i];
	    getch();
	return 0;
}
void HEAP_SORT(int a[],int n)
{
    BUILD_MAXHEAP(a,n);
    for(int i=n-1;i>=1;i--)
    {
	int hsize=i-1;
	int temp;
	temp=a[0];
	a[0]=a[i];
	a[i]=temp;
	MAX_HEAPIFY(a,0,hsize);
    }
}

void BUILD_MAXHEAP(int a[],int n)
{
    int hsize,i;
    hsize=n-1;
    for(i=((n-1)/2);i>=0;i--)
    {
	MAX_HEAPIFY(a,i,hsize);
    }
}

void MAX_HEAPIFY(int a[],int i,int c)
{
    int l=(2*i)+1;
    int r=(2*i)+2;
    int largest;
    int hsize=c;
    if(l<=hsize && a[l]>a[i])
	largest=l;
    else
	largest=i;
    if(r<=hsize && a[r]>a[largest])
	largest=r;
    if(largest!=i)
    {
	int temp;
	temp=a[i];
	a[i]=a[largest];
	a[largest]=temp;
	MAX_HEAPIFY(a,largest,hsize);
    }
}
