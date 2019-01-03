#include <iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int a1[n], a2[m];
	for (int i = 0; i < n; i++)
		cin >> a1[i];
	for (int j = 0; j < m; j++)
		cin >> a2[j];

	int i= 0, j = 0;
	while(i < n && j < m){
		if (a1[i] < a2[j]){
			int temp = a1[i];
			a1[i] = a2[j];
			a2[j] = temp;
			i++;
		}
		else{
			int temp = a2[j];
			a2[j] = a1[i];
			a1[i] = temp;
			j++;
		}
	}

	for (i = 0; i < n; i++)
		cout << a1[i] << " ";
	cout << endl;

	for (int j = 0; j < m; j++)
		cout << a2[j] << " ";
	cout << endl;
}
