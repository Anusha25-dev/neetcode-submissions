class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map1; //value, index
        for(int i=0;i<nums.size();i++){
            int comp=target-nums[i];
            if(map1.find(comp)!=map1.end())
                 return {map1[comp],i};
            map1[nums[i]]=i;
        }
        return {};
    }
};
