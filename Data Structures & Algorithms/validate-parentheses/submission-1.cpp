class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> bracks= {{'(',')'},{'[',']'},{'{','}'}};
        stack<char> st;
        for(char c:s){
            if(c=='{' || c=='(' || c=='['){
                st.push(c);
            }else{
                if(st.empty() || bracks[st.top()]!=c)
                return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
