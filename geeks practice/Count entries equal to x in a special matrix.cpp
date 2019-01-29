#include <iostream>
using namespace std;

int count(int n, int x){
	int count1 = 0;
	for (int i = 1; i<= n && i <= x; i++){
		if (x / i <= n && x % i == 0)
			count1++;
	}
	return count1;
}

int main() 
{ 
    int n = 4; 
    // we can manually assume matrix of order 8*8 
    // where mat[i][j] = i*j , 0<i,j<=n 
    int x =  12; 
    cout << count(n, x); 
    return 0; 
}  
