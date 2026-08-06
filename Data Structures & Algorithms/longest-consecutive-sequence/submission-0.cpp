class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(),nums.end());
        int maxLength=0;
        for(int n:num){
            if(num.find(n-1)!=num.end()) continue;
            int length=1;
            int curr=n;
            while(num.find(curr+1)!=num.end()){
                length++;  curr++;
            }
            maxLength=max(maxLength, length);
        }
        return maxLength;
    }
};
