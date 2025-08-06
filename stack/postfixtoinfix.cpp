#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixtoinfix (string &s){
    int i=0;
    stack <string> st;
    while(i<s.size()){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string cos = '(' + t2 + s[i] + t1 + ')';
            st.push(cos);
        }
        i++;
    }
    return st.top();
    
}

int main() {
    string infix;
    cout << "Enter postfix expression: ";
    cin >> infix;
    cout << "infix expression: " << postfixtoinfix(infix) << endl;
    return 0;
}