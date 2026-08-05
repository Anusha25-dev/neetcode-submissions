class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map1; //value,index
        for(int i=0;i<nums.size();i++){
            if(map1.find(nums[i])!=map1.end()){
                return true;
            }
            map1[nums[i]]=i;
        }
        return false;
    }
};