#include <iostream>
using namespace std;

int main(){
	int k;
	cin >> k;
	int a[] = {2, 3, 5, 9, 10, 11, 12};
	int n = sizeof(a) / sizeof(a[0]);
	int s, diff;

	for (int i = 0; i < n - 1; i++){
		diff = a[i + 1] - a[i];
		s += diff;
		if (s > k){
			cout << a[i] + s - diff;
			break;
		}
	}
}
