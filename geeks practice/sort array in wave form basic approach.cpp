#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	
	for (int i = 0; i < n; i += 2){
		if (i == n - 1)
			break;
		int temp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = temp;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}
