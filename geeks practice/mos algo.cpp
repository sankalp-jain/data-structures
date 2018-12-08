#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int block;

struct Query
{
	int L, R;
};

bool compare(Query x, Query y){
	if (x.L / block != y.L / block)
		return x.L/block < y.L / block;

	return x.R < y.R;
}

void queryResults(int a[], int n, Query q[], int m){
	block = (int)sqrt(n);

	sort(q, q + m, compare);
	int currL = 0, currR = 0, currSum = 0;

	for (int i = 0; i < m; i++){
		int L = q[i].L, R = q[i].R;

		while(currL < L){
			currSum -= a[currL];
			currL++;
		}

		while(currL > L){
			currSum += a[currL - 1];
			currL--;
		}

		while (currR <= R) 
        { 
            currSum += a[currR]; 
            currR++; 
        } 
  
        // Remove elements of previous range.  For example 
        // when previous range is [0, 10] and current range 
        // is [3, 8], then a[9] and a[10] are subtracted 
        while (currR > R+1) 
        { 
            currSum -= a[currR-1]; 
            currR--; 
        } 
  
        // Print sum of current range 
        cout << "Sum of [" << L << ", " << R 
             << "] is "  << currSum << endl;
	}
}

int main(){
	int a[] = {1, 1, 2, 1, 3,  4, 5, 2, 8};
	int n = sizeof(a) / sizeof(a[0]);
	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
	int m = sizeof(q) / sizeof(q[0]);

	queryResults(a, n, q, m);
	return 0;
}
