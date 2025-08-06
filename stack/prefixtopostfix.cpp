#include <iostream>
#include <stack>
#include <string>

using namespace std;

string prefixtopostfix (string &s){
    int i=s.size()-1;
    stack <string> st;
    while(i>=0){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string cos =     t1 + t2 + s[i];
            st.push(cos);
        }
        i--;
    }
    return st.top();
    
}

int main() {
    string infix;
    cout << "Enter prefix expression: ";
    cin >> infix;
    cout << "postfix expression: " << prefixtopostfix(infix) << endl;
    return 0;
}