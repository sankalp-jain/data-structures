#include<iostream>
using namespace std;

int fibo(int n){
	if (n == 1){
		return 1;
	}
	if (n == 0)
		return 0;

	int smallOutput1 = fibo(n - 1);
	int smallOutput2 = fibo(n - 2);
	int output = smallOutput1 + smallOutput2;
	return output;	
}

int main(){
	int a = fibo(6);
	cout << a << endl;
	return 0;
}
