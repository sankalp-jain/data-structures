#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> vt;
		vector<int> vt1;
		int n;
		cin >> n;
		int a[n][n];
		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
				if (a[i][j] == 0){
					vt.push_back(i);
					vt1.push_back(j);
				}
			}
		}
		
		for (int i = 0; i < vt.size(); i++){
			for (int j = 0; j < n; j++)
				a[vt[i]][j] = 0;
		}
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < vt1.size(); j++)
				a[i][vt1[j]] = 0;
		}
		
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cout << a[i][j] << endl;
	}
}
