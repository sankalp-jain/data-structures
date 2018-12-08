#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char x) { 
  switch (x) { 
  case '+': 
  case '-': 
  case '/': 
  case '*': 
    return true; 
  } 
  return false; 
}

int main(){
	string s;
	cin >> s;
	stack<string> st;
	for (int i = s.length() - 1; i > -1; i--){
		if (!isOperator(s[i])){
			cout<<s[i]<<endl;
			st.push(string(1, s[i]));
		}
		else{
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();

			string temp = "(" + a + s[i] + b + ")";
			st.push(temp);
		}
	}
	cout<< st.top();
}

