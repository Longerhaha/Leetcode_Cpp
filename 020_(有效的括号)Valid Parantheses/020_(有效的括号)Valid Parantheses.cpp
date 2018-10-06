class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st;
        for( int i = 0; i < len; i++ ){
            if(s[i] == ')'){
                if(st.empty() || st.top() != '(') return false;
                else st.pop();
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '[') return false;
                else st.pop();
            }
            else if(s[i] == '}'){
                if(st.empty() || st.top() != '{') return false;
                else st.pop();
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};