#include "bits/stdc++.h"
using namespace std;
bool syntaxerror(string s){
    stack<char>st;
     string res;
    for (size_t i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(' or c =='{' or c =='[')
        {
            st.push(c);
        }
        else if(c==')' or c =='}' or c == ']'){
            if(st.empty()) return false;
            if((c == ')' and st.top() == '(')||
                (c == ']' and st.top() == '[')||
                (c == '}' and st.top() == '{'))
            {
                st.pop();
            }
            else {
                return false;
            }
    }
    }
   return st.empty();
}
int main(){
    string s;
    cin>>s;
    if(syntaxerror(s)) cout<<"No Syntax error"<<endl;
    else{
        cout<<"There is a syntax error"<<endl;
    }
    return 0;
}
