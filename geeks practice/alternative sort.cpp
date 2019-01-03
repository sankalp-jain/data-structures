#include <iostream>
#include <algorithm>
using namespace std;

void alternativeSort(int a[], int n){
	int start = 0;
	int end = n - 1;
	
	while(start < end){
		cout << a[end] << " " << a[start] << " ";
		start++;
		end--;
	}
	if (n % 2 != 0)
		cout << a[n / 2];
	
}

int main(){
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	alternativeSort(a, n);
}
