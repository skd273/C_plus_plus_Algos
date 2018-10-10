#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int helper2(int arr[],int low,int high){

    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or equal to the
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void helper(int arr[],int low,int high){
   if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = helper2(arr, low, high);

        // Separately sort elements before partition and after partition
        helper(arr, low, pi - 1);
        helper(arr, pi + 1, high);
    }
}

void quickSort(int input[], int size) {
  if(size==0){return;}

  helper(input,0,size-1);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    //quicksort function requires 2 parameters - (array , size of the array)
    
    quickSort(arr,n);
    
    //printing the sorted array
    cout<<"Sorted array:";
    printArray(arr, n);
    return 0;
}
