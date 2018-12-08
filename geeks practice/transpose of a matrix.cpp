#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n][n];
	    int at[n][n];
	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	            cin >> a[i][j];
	            at[j][i] = a[i][j];
	        }
	    }
	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	            cout << at[i][j] << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
