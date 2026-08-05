class Solution {
public:
    bool isAnagram(string s, string t) {
        //unordered_map<char,int> map1; //character and the number of times
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        unordered_map<char,int> map1; //character and the number of times
        
        for(auto i:s){
            if(map1.find(i)==map1.end())    map1[i]=1;
            else
            map1[i]++;
        }
        
        for(auto i:t){
            if(map1.find(i)==map1.end()) return false;
            map1[i]--;
            if(map1[i]<0) return false;
        }
        for(auto &val:map1){
            if(val.second!=0) return false;
        }
        return true;
    }
};
