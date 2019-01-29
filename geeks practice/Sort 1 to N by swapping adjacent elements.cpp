#include <bits/stdc++.h>
using namespace std;

bool sortedAfterSwap(int a[], int b[], int n){
	int i, j;

	for (int i = 0; i < n - 1; i++){
		if (b[i]){
			j = i;
			while(b[j])
				j++;

			sort(a + i, a + 1 + j);
			i = j;
		}
	}
	for (i = 0; i < n; i++){
		if (a[i] != i + 1)
			return false;
	}
	return true;
}

int main(){
	int a[] = {1, 2, 5, 3, 4, 6};
	int b[] = {0, 1, 1, 1, 0};

	int n = sizeof(a) / sizeof(a[0]);
	if (sortedAfterSwap(a, b, n))
		cout << "Can be sorted" << endl;
	else
		cout << "Can't be sorted" << endl;

	return 0;	
}
