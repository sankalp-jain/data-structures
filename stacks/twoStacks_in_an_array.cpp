#include <iostream>
#include <stack>

using namespace std;

class twoStacks{
	int arr[7];
	int index1;
	int index2;
	
public:
	twoStacks(){
		index1 = 0;
		index2 = 6;
	}

	void push(string s, int element){
		if (s == "head1"){
			if (index1 <= index2){
				arr[index1] = element;
				index1++;
				cout<<element<<" "<<index1<<endl;
			}
			else
				cout<<"Stack Full"<<endl;
		}
		else{
			if (index2 != index1){
				arr[index2] = element;
				index2--;
				cout<<element<<" "<<index2<<endl;
			}
			else
				cout<<"Stack Full"<<endl;
		}
	}


	void pop(string s){
		if (s == "head1"){
			index1--;
		}
		else
			index2++;
	}

	int top(string s){
		if (s == "head1")
			return arr[index1 - 1];
		else
			return arr[index2 + 1];
	}
};

int main(){
	twoStacks st;
	st.push("head1", 10);
	st.push("head2", 20);
	st.push("head2", 30);
	st.push("head2", 40);
	st.push("head1", 50);
	st.push("head1", 80);
	st.push("head1", 100);

	cout<<st.top("head1")<<endl;
	cout<<st.top("head2")<<endl;

	st.pop("head1");
	st.pop("head2");
	st.pop("head1");
	st.pop("head2");
	st.pop("head1");

	cout<<st.top("head1")<<endl;
	cout<<st.top("head2")<<endl;

	return 0;
}
