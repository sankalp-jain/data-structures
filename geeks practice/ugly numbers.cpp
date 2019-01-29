#include <iostream>
using namespace std;

int main(){
	int n = 5832;
	
	while(n % 2 == 0){
		cout << n<< endl;
		n = n / 2;
	}
	while(n % 3 == 0){
		n = n / 3;
	}
	while(n % 5 == 0){
		n = n / 5;
	}
	cout << n << endl;
	if (n == 1)
		cout << "Ugly" << endl;
	else
		cout << "Not Ugly" << endl;
}
