#include <iostream>
#include<algorithm>
using namespace std;

int main(){
	int m = 3, n = 4;

	int a1[] = {2, 7, -1, -1, -1, 10, -1};
	int a2[] = {5, 8, 12, 14};

	sort(a1, a1 + m + n);
	int currIndex = 0, ar1Index = n, ar2Index = 0;
	int index, array;
	for (int i = 0; i < m + n; i++){
		
		if (ar1Index == m + n){
			for (int j = currIndex; j < m + n; j++){
				a1[j] = a2[ar2Index];
				ar2Index++;
			}
			break;
		}
		if (ar2Index == n){
			for (int j = currIndex; j < m + n; j++){
				a1[j] = a1[ar1Index];
				ar1Index++;
			}
			break;
			
		}
		
		if (a1[ar1Index] < a2[ar2Index]){
			array = 1;
			index = ar1Index;
		}
		else{
			array = 2;
			index = ar2Index;
		}
	
		if (array == 1){
			int temp = a1[ar1Index];
			a1[ar1Index] = a1[currIndex];
			a1[currIndex] = temp;
			currIndex++;
			ar1Index++;
		} 
		else{
			int temp = a2[ar2Index];
			a2[ar2Index] = a1[currIndex];
			a1[currIndex] = temp;
			currIndex++;
			ar2Index++;
		}
	}	
	for (int i = 0; i < m + n; i++)
		cout << a1[i] << " ";
		cout << endl;
}
