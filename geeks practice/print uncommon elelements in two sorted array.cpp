#include <iostream>
using namespace std;

int main(){
	int a[] = {10, 20, 30};
	int b[] = {40, 50};
	int size1 = sizeof(a)  /sizeof(a[0]);
	int size2 = sizeof(b) / sizeof(b[0]);

	int i = 0, j = 0;
	while(i < size1 || j < size2){
		if (i == size1 && j != size2){
			while(j < size2){
				cout << b[j] << endl;
				j++;
			}
			break;
		}

		if (j == size2 && i != size1){
			while(i < size1){
				cout<<a[i] << endl;
				i++;
			}
			break;
		}

		if (a[i] < b[j]){
			cout << a[i] << endl;
			i++;	
		}
		else if(a[i] > b[j]){
			cout << b[j] << endl;
			j++;
		}
		else{
			i++;
			j++;
		}
	}
}
