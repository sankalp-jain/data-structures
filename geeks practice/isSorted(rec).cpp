#include<iostream>
using namespace std;

bool isSorted(int a[], int n){
	if(n == 1)
		return true;
	
	int smallOutput = isSorted(a,n - 1);
	if(smallOutput == true && a[n - 1] > a[n - 2])
		return true;
	else
		return false;
}

int main(){
	int a[] = {1, 2, 3, 6, 5};
	bool b = isSorted(a, 5);
	cout << b;
}
