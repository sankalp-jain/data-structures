#include <iostream>
using namespace std;

int isDivisible(int set[], int n, int m){
	if(n == 1)
		return set[0];
	
	int sum = isDivisible(set, n - 1, m);
	cout << sum << endl;
	if(sum % m == 0)
		return sum;
	return sum + set[n - 1];
}

int main(){
	int set[] = {3, 1, 7, 5};
	int m = 6;
	int n = sizeof(set) / sizeof(set[0]);
	int b = isDivisible(set, n, m);
	cout << b;
}
