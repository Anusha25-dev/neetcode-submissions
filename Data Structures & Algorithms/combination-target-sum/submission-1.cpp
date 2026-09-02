class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums,target,current,0,result);
        return result;
    }
    void backtrack(vector<int>& nums,int target,vector<int>& current,int start,vector<vector<int>>& result){
        if(target==0){ //target reduces with each new number; target==0 means that a valid combo has been successfully found
            result.push_back(current);
            return;
        }
        if(target<0) return; //STOP
        for(int i=start; i<nums.size();i++){
            current.push_back(nums[i]); //choose 1 element
            backtrack(nums,target-nums[i],current,i,result);
            current.pop_back(); //undo the choice
        }
    }
};
