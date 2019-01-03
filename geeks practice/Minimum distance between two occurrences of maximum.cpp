#include <iostream>
using namespace std;

class minDist{
public:
	int max;
	int index;
	minDist(){
		max = 0;
		index = 0;
	}
};

int main(){
	minDist md;
	cout << md.max << endl;
	cout << md.index << endl;
}
