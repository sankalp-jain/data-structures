#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int s = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		s += a[i] * i;
	cout << s << endl;
}
