#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<char> st;
	char ch[] = "Sankalp";
	while(*ch != '\0'){
		if (*ch != ' '){
			cout<<*ch;	
			st.push(*ch);
			*ch = *(ch + 1);
		}
		else{
			while(!st.empty()){
				cout<<st.top()<<endl;
				st.pop();
			}
			*ch = *(ch + 1);
		}
		
	}
}
