class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int p:prices){
            minPrice=min(minPrice,p); //find min price till now - now or previously
            maxProfit=max(maxProfit, p-minPrice); //find max profit - now or previously
        }
        return maxProfit;
    }
};
