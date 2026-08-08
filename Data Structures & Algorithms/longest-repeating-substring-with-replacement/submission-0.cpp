class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={0};
        int l=0;
        int maxLength=0;
        int maxFreq=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            int window=r-l+1;
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            if(window-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLength=max(maxLength,r-l+1);
        }
        return maxLength;
    }
};
