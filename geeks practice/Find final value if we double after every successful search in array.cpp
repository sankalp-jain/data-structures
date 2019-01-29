//Will not work if k == 1
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a[] ={1, 3, 2};
	int k = 2;
	int max = k;
	int n = sizeof(a) / sizeof(a[0]);
	int c = 0;
	for (int i = 0; i < n; i++){
		double val = log(a[i]) / log(k);
		if (floor(val) == val && a[i] >= max){
			
			max = a[i];
			c++;
		}
	}
	if (c == 0)
		cout << k << endl;
	else
		cout << 2 * max << endl;
}
