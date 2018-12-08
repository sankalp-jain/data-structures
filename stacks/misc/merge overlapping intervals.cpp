#include <iostream>
#include <stack>
using namespace std;

class startEndTime{
public:

	int startTime;
	int endTime;

	startEndTime(int startTime, int endTime){
		this -> startTime = startTime;
		this -> endTime = endTime;
	}
};

int main(){
	stack<startEndTime> s1(10, 20);

	startEndTime s = s1.top();
	cout << s -> startTime;
}
