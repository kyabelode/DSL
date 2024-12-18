#include "bits/stdc++.h"
using namespace std;
int prec(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' or c=='-') return 1;
    else return -1;
    
}
string infixtopostfix(string s){
        stack<char> st;
        string res;
        for (size_t i = 0; i < s.length(); i++)
        {
        char c = s[i];
        if((c>='a' and c<='z' )||(c>='0' and c<='9' )||(c>='A' and c<='Z')){
            // push into string 
            res+=c;
        }
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() and st.top()!='('){
                // push into string and keep going
                res +=st.top();
                // pop from stack
                st.pop();
            }
            // pop from stack
            st.pop();
        }
        else{
            while(!st.empty() and prec(c)<=prec(st.top())){
                //  push to the string 
                res+=st.top();
                // pop from the stack
                st.pop();
            }
            // if not greater push it back to stack
            st.push(c);
        }
        }
        while(!st.empty()){
            // return the res 
            res+=st.top();
            // empty the stack
            st.pop();
        }
        // return res 
        return res;
}
int main(){
    string s;
    cin>>s;
    string k = infixtopostfix(s);
    cout<<k<<endl;
}