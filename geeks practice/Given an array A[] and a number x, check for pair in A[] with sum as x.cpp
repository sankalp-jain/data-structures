#include <iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	int start = 0;
	int finish = a[n - 1];

	while(start < finish){
		if (a[start] + a[finish] == x)
			cout << a[start] << " " << a[finish] << endl;
		else if (a[start] + a[finish] < x){
			cout << "cjjdcn" << endl;
			start++;
		}
		else
			finish--;
	}
}
