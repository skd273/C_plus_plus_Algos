// Insertion Sort -> n**2 time complexity
#include <bits/stdc++.h>
using namespace std;

int main(){
	int array[6] = {5, 2, 4, 6, 1, 3};
	int key, i;
	for(int i=0; i<6; i++){
		cout << "A[" << i << "] = " << array[i] << endl ;  
	}
	for(int j=1; j<=5; j++){
		key = array[j];
		i=j-1;
		while(i>=0 && array[i]>key){
			array[i+1] = array[i];
			i=i-1;
		}
		array[i+1]=key;	
	}
	cout << "\n";
	for(int i=0; i<6; i++){
		cout << "A[" << i << "] = " << array[i] << endl; 
	}
}
