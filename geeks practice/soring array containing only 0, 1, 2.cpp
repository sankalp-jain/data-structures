#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int count = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == 0){
			int temp = a[i];
			a[i] = a[count];
			a[count] = temp;
			count++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	int count1 = count;
	for (int i = count; i < n; i++){
		if (a[i] == 1){
			int temp = a[i];
			a[i] = a[count1];
			a[count1] = temp;
			count1++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;	
}
