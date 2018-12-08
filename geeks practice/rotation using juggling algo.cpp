#include <iostream>
using namespace std;

int gcdNum(int n, int d){
	int r;
	while(d != 0){
		r = n % d;
		n = d;
		d = r;
	}
	return n;
}

int main(){
	int n, d;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	int gcd = gcdNum(n, d);

	for (int i = 0; i < gcd; i++){
		int temp = a[i];
		int j = i;
		int k;
		while(1){
			k = j + d;
			if (k >= n)
				k = k - n;
			if (k == i)
				break;
			a[j] = a[k];
			j = k;
		}
		a[j] = temp;
	}
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n"; 
}
