#include<bits/stdc++.h>
using namespace std;

// to check the precedence of the operator 
int precedence(char c){
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

// converting infix to postfix
void infixToPostfix(string s){

	stack <char> st;
	st.push('N');
	string ns;

	for(int i=0;i<s.length();i++){
		if((s[i] >= 'A' && s[i] <= 'Z') || s[i] >= 'a' && s[i] <= 'z'){
			ns+=s[i];
		}else if(s[i] == '('){
			 st.push(s[i]);	
		}
		else if(s[i] == ')' ) {
			while(st.top() != 'N' && st.top() != '('){
				char c = st.top();
                st.pop();
               	ns += c;
			} 
			if(st.top() == '('){
                char c = st.top();
                st.pop();
            }
		}
		else{
			while(st.top() != 'N' && precedence(s[i]) <= precedence(st.top())){
				char c = st.top();
                st.pop();
                ns += c;
			}
			st.push(s[i]);
		}
	}
	
	// pop all the elements from the stack
	while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
      
    cout << ns << endl;
}

int main(){

	string s = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(s);

}