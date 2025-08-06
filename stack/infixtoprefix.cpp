#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int priority(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infixToprefix( string &s){

    reverse(s.begin(),s.end());
    for(int i=0; i<s.size(); i++){ 
        if(s[i]=='('){
            s[i] = ')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }

    }
    stack<char> st;
    string ans = "";
    int i = 0;
    while(i < s.size()){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i]; // Add operand directly to result, not to stack
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){ // Changed st.empty() to !st.empty()
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // Remove the '(' from stack
        }
        else{
            while(!st.empty() && priority(s[i]) < priority(st.top())){ // Changed priority to strictly less
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    
    // Move this outside the while loop
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
     
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    cout << "Prefix expression: " << infixToprefix(infix) << endl;
    return 0;
}



