#include <iostream>
#include <stack>
#include <string>

using namespace std;

string prefixtoinfix(string &s){
    int i = s.size() - 1; // Start from last valid index, not s.size()
    stack<string> st;
    while(i >= 0){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string cos = '(' + t1 + s[i] + t2 + ')';
            st.push(cos);
        }
        i--;
    }
    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    cout << "Infix expression: " << prefixtoinfix(prefix) << endl;
    return 0;
}