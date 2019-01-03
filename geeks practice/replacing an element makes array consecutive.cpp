#include <iostream>
#include<algorithm>
using namespace std;

int main(){
	int a[] = {5, 6, 7, 9, 8};
	int n = sizeof(a) / sizeof(a[0]);
	int c = 0, d = 0;
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
		if (a[i + 1] - a[i] != 1)
			c++;

	for (int i = n - 1; i >= 1; i--)
		if (a[i] - a[i - 1] != 1)
			d++;

	if(c > 1 || d > 1)
		cout << "Ans not found" << endl;
	else if (c == 1 || d == 1){
		if (c == 1)
			cout << a[0] << endl;
		else
			cout << a[n - 1] << endl;
	}
	else if (c == 0 && d == 0)
		cout << "Array is consecutive" << endl;
}
