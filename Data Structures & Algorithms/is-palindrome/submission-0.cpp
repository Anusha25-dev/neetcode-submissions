class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for(char c:s){
            if(isalnum(c))
                res+=tolower(c);
        }

        stack<char> st;
        for(int i=0;i<(res.size())/2;i++){
            st.push(res[i]);
        }
        int n=res.size();
        int start=0;
        if(n%2==0)
        start=n/2;
        else
        start=n/2 +1;
        for(int i=start;i<res.size();i++){
            if(st.top()!=res[i]) return false;
            st.pop();
        }
        return true;
    }
};
