#include <iostream>
#include <sstream>
#include <string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];

	string aString[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++){
		itoa(a[i], aString, 10);
		cout << aString[i] <<endl;
	}

	sort(aString, aString + n);
	for (int i = 0; i < n; i++){
		cout << aString[i] << " ";
	}
}
