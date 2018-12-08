#include <iostream>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int start = 0;
	int finish = n - 1;
	int last = a[n - 1];
	while(start <= finish){
		int m = (start + finish) / 2;
		if (a[m] == x){
			cout << m;
			break;
		}
		else if (a[m] > x && x > last)
			finish = m - 1;
		else
			start = m + 1;
	}
}
