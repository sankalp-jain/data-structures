#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<int> s){
	if (s.empty()){
		return;
	}
	s.pop();
	reverse(s);
	if (!s.empty())
		cout<<s.top();
}

int main(){
	stack<int> st;
	int n = 6899;
	while(n > 0){
		st.push(n % 10);
		n /= 10;
	}
	reverse(st);
	cout<<st.top();
	return 0;
}
