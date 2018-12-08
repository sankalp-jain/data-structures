#include <iostream>
using namespace std;

int main(){
	int n, d;
	cin >> n >> d;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < d; i++){
		int temp = a[0];
		for (int j = 0; j < n; j++){
			a[j] = a[j + 1];
		}
		a[n-1] = temp;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}