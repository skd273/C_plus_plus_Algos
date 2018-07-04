// Bubble Sort algorithm
#include <bits/stdc++.h>
using namespace std;

int* BubbleSort(int array[], int n){
	int temp=0, i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n; j++){
			if(array[j]>array[j+1]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	return array;
}

int main(void){
	int array[6] = {23, 56, 1, 99, 2, 31};
	for(int i=0; i<6; i++){
		cout << "A[" << i << "] = " << array[i] << endl;
	}
	cout << "\n";
	int *a = BubbleSort(array, 6);
	for(int i=0; i<6; i++){
		cout << "A[" << i << "] = " << a[i] << endl;
	}
	return 0;
}
