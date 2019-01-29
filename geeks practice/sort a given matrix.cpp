#include <iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	int temp[n * n];
	int k = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			temp[k] = a[i][j];
			k++;
		}
	}

	sort(temp, temp + n * n);
	k = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			a[i][j] = temp[k];
			k++;
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
