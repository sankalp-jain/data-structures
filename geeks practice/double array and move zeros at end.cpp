#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != 0 && a[i] == a[i + 1]){
			a[i + 1] = 0;
			a[i] *= 2;
			a[count] = a[i];
			count++;
		}
		else if(a[i] != 0){
			a[count] = a[i];
			count++;
		}
	}
	
	for (int i = count; i < n; i++)
		a[i] = 0;
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
