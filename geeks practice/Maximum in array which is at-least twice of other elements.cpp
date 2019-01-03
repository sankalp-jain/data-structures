#include <iostream>
#include <limits.h>
using namespace std;

int main(){
	int a[] = {1, 2, 3, 4};
	int size = sizeof(a) / sizeof(a[0]);

	int max1 = INT_MIN;
	int max2 = INT_MIN;
	for (int i = 0; i < size; i++){
		if (a[i] > max1){
			max2 = max1;
			max1 = a[i];
		}
	}
	if (max1 >= 2 * max2)
		cout << max1;
	else
		cout << -1;
}
