class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char, int> need, window; //2 maps - 1 for how many of char reqd. & 1 for how many of char. present in the window l to r

        for(char c:t){
            need[c]++;
        }

        int have=0;//no. of distinct charcaters found (which are reqd.)
        int needCount=need.size();//how many different characters are reqd.
        int l=0; 
        int minLength=INT_MAX;
        int minStartIndex=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(need.find(c)!=need.end() && window[c]==need[c])
                have++;
            while(have==needCount){
                if(r-l+1<minLength){
                    minLength=r-l+1;
                    minStartIndex=l;
                }
                window[s[l]]--;
                if(need.find(s[l])!= need.end() && window[s[l]]<need[s[l]]) //l element in need but the number of occurrences reqd of the s[l] element is now lesser than the reqd occurrences because of line 26
                    have--;
                l++;
            }
        }
        
            return minLength==INT_MAX?"":s.substr(minStartIndex,minLength);
        }
        
    
};
