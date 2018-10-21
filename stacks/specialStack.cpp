#include <iostream>
#include <stack>

using namespace std;

class SpecialStack{
	stack<int> st;
	stack<int> min;

public:
	void pushSpecial(int element){
		st.push(element);
		if (!min.empty()){
			int x = min.top();
			if (x > element)
				min.push(element);
		}
		else
			min.push(element);
	}

	void popSpecial(){
		int x = st.top();
		int y = min.top();
		

		if(x > y)
			st.pop();
			
		else{
			min.pop();
			st.pop();
		}
	}

	int getMin(){
		return min.top();
	}
	
	int size(){
		return st.size();
	}
	
	bool empty(){
		return st.empty();
	}
};

int main(){
	SpecialStack st;
	st.pushSpecial(18);
	st.pushSpecial(19);
	st.pushSpecial(29);
	st.pushSpecial(15);
	st.pushSpecial(16);
	
	cout<<st.getMin()<<endl;

	st.popSpecial();
	st.popSpecial();

	cout<<st.getMin()<<endl;
	
	cout<<st.size()<<endl;
	cout<<st.empty()<<endl;
	return 0;

}
