#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[] = {1, 6, 9, 4, 3, 7, 8, 2};
	int size = sizeof(a) / sizeof(a[0]);

	sort(a, a + size);
	int i = 0, j = size - 1;
	while(i <= j){
		if (i == j){
			cout << a[i];
			i++;
		}
		else{
			cout << a[j] << " ";
			cout << a[i] << " ";
			j--;
			i++;
		}
	}
}
