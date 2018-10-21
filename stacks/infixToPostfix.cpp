#include <iostream>
#include <stack>

using namespace std;

int prec(char c){
	if (c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

int main(){
	string s;
	cin >> s;
	stack<char> st;
	st.push('N');
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
			int preced1 = prec(s[i]);
			int preced2 = prec(st.top());
			if (preced1 > preced2)
				st.push(s[i]);
			else{
				while(prec(st.top()) >= preced1 && st.top() != 'N'){
					cout<<st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}

		else if(s[i] == '('){
			st.push(s[i]);
		}

		else if (s[i] == ')'){
			while(st.top()!= '('){
				cout<<st.top();
				st.pop();
			}
			st.pop();
		}

		else
			cout<<s[i];
	}
	while(st.top() != 'N'){
		cout<<st.top();
		st.pop();
	}
}
