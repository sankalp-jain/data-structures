#include <iostream>
using namespace std;


int main(){
	int a[] = {1, 2, 2, 1};
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 1; i <= n - 1; i+=2){
		if (a[i] < a[i - 1]){
			int t = a[i];
			a[i] = a[i - 1];
			a[i - 1] = t;
		}
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
		if (a[i] < a[i + 1] && i < n){
			int t = a[i];
			a[i] = a[i + 1];
			a[i + 1] = t;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
