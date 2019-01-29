#include <iostream>
using namespace std;

int main(){
	int a[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
	int n = sizeof(a) / sizeof(a[0]);

	int i = 0;
	while (i < n){
		if  (a[i] == i || a[i] == -1)
			i++;
		else{
			int t = a[i];
			a[i] = a[t];
			a[t] = t;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
