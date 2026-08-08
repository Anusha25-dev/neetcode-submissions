class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //unordered_map<int, int> val; //price, index
        int maxProfit=0;
        // for(int i=0;i<prices.size();i++){
        //     val[prices[i]]=i;
        // }
        for(int i=0;i<prices.size();i++){
            int profit=0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]>prices[i])
                    profit=prices[j]-prices[i];
                maxProfit=max(profit,maxProfit);
            }
        }
        return maxProfit;
    }
};
