#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixtoprefix (string &s){
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
            string cos =    s[i] + t2 + t1 ;
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
    cout << "prefix expression: " << postfixtoprefix(infix) << endl;
    return 0;
}