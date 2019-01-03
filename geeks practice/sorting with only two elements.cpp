#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	int c = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 0)
			c++;
	}

	int count = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == 1){
			a[count] = 0;
			count++;
		}
	}

	for (int i = c; i < n; i++)
		a[i] = 1;

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout << a[i] << " ";
	}
	cout << endl;
}