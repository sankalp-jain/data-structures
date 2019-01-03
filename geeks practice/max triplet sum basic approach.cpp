#include <iostream>
using namespace std;

int main(){
	int a[] = {9, 8, 20, 3, 4, -1, 0};
	int size = sizeof(a) / sizeof(a[0]);
	int s;
	int max = 0;
	for (int i = 0; i < size - 2; i++){
		for (int j = i + 1; j < size - 1; j++){
			for (int k = j + 1; k < size ; k++){
				s = a[i] + a[j] + a[k];
				if (s > max)
					max = s;
			}
		}
	}
	cout << max << endl;
}
