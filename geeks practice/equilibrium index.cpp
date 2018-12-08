#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int s = 0;
	int *a = new int[n + 1];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		s += a[i];
	}
	int s1 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			s1 += a[i];
			if (s - s1 == s1 - a[i]){
				cout << i << endl;
			}
		}
		else
			s1 += a[i];
	}
}
