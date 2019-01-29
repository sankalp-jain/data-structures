#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
	int n = sizeof(a) / sizeof(a[0]);
	srand(time(NULL));
	for  (int i = n - 1; i > 0; i--){
		int j = rand() % (i + 1);
		int t = a[j];
		a[j] = a[i];
		a[i] = t;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
