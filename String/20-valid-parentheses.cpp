class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 2) return false;
        stack<char> st;
        for(auto& c : s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else if(st.size()<1) return false;
            else if(c == ')'){
                if(st.top() != '(') return false;
                else st.pop();
            } else if (c == '}'){
                if(st.top() != '{') return false;
                else st.pop();
            } else if (c == ']'){
                if(st.top() != '[') return false;
                else st.pop();
            }
        }
        if(st.size()) return false;
        return true;
    }
};