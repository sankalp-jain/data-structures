#include <iostream>
using namespace std;

int main(){
	int n = 8;
	int fibo[n + 2];
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i < n + 1; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n];
}
