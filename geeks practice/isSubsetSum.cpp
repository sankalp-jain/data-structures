#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum){
	if(sum == 0)
		return	true;

	if(n == 0 && sum != 0)
		return false;

	if(set[n-1] > sum)
		return isSubsetSum(set, n - 1, sum);

	return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main(){
	int set[] = {3, 34, 4, 12}, sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	bool b = isSubsetSum(set, n, sum);
	cout << b;
}