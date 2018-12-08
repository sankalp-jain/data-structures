#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Query{
	int L, R;
};

int block;

bool compare(Query x, Query y){
	if (x.L / block != y.L / block)
		return x.L / block < y.L / block;

	return x.R < y.R;
}

void queryResult(int a[], int n, Query q[], int m){
	block = sqrt(n);
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
	int arr[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
	int m = sizeof(q) / sizeof(q[0]);

	queryResult(arr, n, q, m);
}
