#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = 0; i < n; i+=2){
		if (i - 1 > 0){
			if (a[i - 1] > a[i]){
				int temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp; 
			}
		}
		else if (i + 1 > n - 1){
			if (a[i + 1] > a[i]){
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}
