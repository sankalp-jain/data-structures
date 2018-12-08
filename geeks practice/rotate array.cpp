#include <iostream>
using namespace std;

int main(){
	int n, d;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int temp[d];
	for (int i = 0; i < d; i++){
		temp[i] = a[i];
	}
	for (int i = 0; i < n - d; i++)
		a[i] = a[i + d];

	for (int i = 0; i < d; i++){
		a[i + n - d] = temp[i];
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

}
