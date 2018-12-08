#include <iostream>
using namespace std;

void reverse(int *arr, int start, int end){
	while (start < end) 
    { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
}

int main(){
	int n, d;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	reverse(a, 0, d - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	reverse(a, d, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	reverse(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

}
