#include<bits/stdc++.h>
using namespace std;

#define max 1000

class Stack{
	int top;

public:
	int a[max];

	Stack() {top = -1;}
	bool push(int x);
	int pop();
	bool isEmpty();
};
	
bool Stack::push(int x){
	if(top >= max-1){
		cout<<"Stack Overflow"<<endl;
		return false;
	}else{
		a[++top] = x;
		cout<<x<<" pushed at the top of the stack"<<endl;
		return true;
	}
}

int Stack::pop(){
	if(!isEmpty()){
		int x = a[top--];
		return x;
	}else{
		cout<<"Stack Underflow"<<endl;
		return 0;
	}
}

bool Stack::isEmpty(){
	return (top<0);
}

int main(){
	class Stack s;
	s.push(10);
	s.push(20);

	cout<<s.pop()<<" poped from the top of stack"<<endl;;


}