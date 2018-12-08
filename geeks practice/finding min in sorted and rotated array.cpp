#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	int val = INT_MIN;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int l = 0, h = n - 1;
	while(l < h){
		int m = (l + h) / 2;
		if (arr[m] < arr[m - 1] && arr[m] < arr[m + 1]){
			val = arr[m];
			break;
		}
		else if (arr[m] > arr[h - 1])
			l = m + 1;
		else
			h = m - 1;
	}
	if (val == INT_MIN)
		val = arr[0];
	cout << val;
}
