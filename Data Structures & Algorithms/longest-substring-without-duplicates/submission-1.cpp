class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map1; //character - index it was last found at
        int l=0;
        int maxLength=0;
        for(int r=0;r<s.size();r++){
            if(map1.find(s[r])!=map1.end()&& map1[s[r]]>=l){
                l=map1[s[r]]+1;
            }
            map1[s[r]]=r;
            maxLength=max(maxLength,r-l+1);
        }
        return maxLength;
    }
};
