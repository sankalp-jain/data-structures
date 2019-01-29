#include <iostream>
using namespace std;

int main() 
{ 
    int n = 5; 
    int mat[n][n] ={ { 1, 1, 1, 1, 0 },
                    { 0, 1, 0, 1, 1 },
                    { 1, 0, 0, 0, 1 },
                    { 0, 1, 0, 1, 0 },
                    { 0, 1, 0, 0, 1 } };   
    int flip = 0;

    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++){
    		if (mat[i][j] != mat[j][i])
    			flip++;
    	}
    }n
    cout << flip / 2 << endl;
    return 0; 
} 
