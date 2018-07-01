// Selection sort --> n**2 time complexity
#include <bits/stdc++.h>
using namespace std;

int main(void){
	int array[6] = {5, 2, 4, 6, 1, 3};
	int index_min=0, temp=0;
	for(int i=0; i<6; i++){
		cout << "A[" << i <<"] = " << array[i] << endl;
	}
	for(int i=0; i<5; i++){
		i = index_min;
		for(int j=1; j<6; j++){
			if(array[index_min]>array[j]) index_min=j;
		}
		temp=index_min;
		index_min=i;
		i=temp;
	}
	cout << "\n";
	for(int i=0; i<6; i++){
		cout << "A[" << i << "] = " << array[i] << endl;
	}
	return 0;
}
