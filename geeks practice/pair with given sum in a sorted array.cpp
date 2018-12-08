#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n;
		int a[n], flag = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> k;
		int low = 0;
		int high = n - 1;
		while(low < high){
			if (a[low] + a[high] == k){
				cout << a[low] << " " << a[high] << " " << k << endl;
				flag = 1;
				low++;
				high--;
			}
			else if (a[low] + a[high] < k)
				low++;
			else
				high--;
		}
		if (flag == 0)
			cout << -1 << endl;	
	}
}
