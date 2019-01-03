#include <iostream>
using namespace std;

int main(){
	int x;
	cin >> x;
	
	int a[] = {1, 1, 3, 3, 3, 3, 4, 6};
	int n = sizeof(a) / sizeof(a[0]);

	int start = 0, finish = n - 1;
	while(start <= finish){
		int mid = (start + finish) / 2;
		if (mid != 0 && a[mid] == x && a[mid - 1] != x){
			cout << mid << endl;
			break;
		}
		else if (a[mid] == x && a[mid - 1] == x)
			finish = mid - 1;
		else{
			if (a[mid] < x){
				start = mid + 1;				
			}
			else
				finish = mid - 1;
		} 
	}
	start = 0, finish = n - 1;
	while(start <= finish){
		int mid = (start + finish) / 2;
		if (mid != n - 1 && a[mid] == x && a[mid + 1] != x){
			cout << mid;
			break;
		}
		else if (a[mid] == x && a[mid + 1] == x)
			start = mid + 1;
		else{
			if (a[mid] < x){
				start = mid + 1;				
			}
			else
				finish = mid - 1;
		} 
	}
}
