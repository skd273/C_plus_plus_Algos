/**                      Binary Search by Sahaj Jain                       **/
#include<iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int ele) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is found return mid  
        
        if (arr[mid] == ele)   
            return mid; 
  
        // If element is smaller than mid element then search at left part 

        if (arr[mid] > ele)  
            return binarySearch(arr, l, mid-1, ele); 
  
        // If element is larger than mid element then search at right part 

        return binarySearch(arr, mid+1, r, ele); 
   } 
   return -1;         //if not found
} 
  
int main(void) 
{ 
   int arr[] = {1,2,3,4,5,6,7,8,9,10}; 
   
   int ele = 10; 
   int ans=binarySearch(arr, 0, 9 , ele);
   
   if(ans != -1) 
   cout<<ans+1<<endl;
   else cout<<" not present";
   
   return 0; 
}
