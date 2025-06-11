class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n=prices.size();
        int profit=INT_MIN;

        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);

            mini=min(mini,prices[i]);
        }
        if(profit<0){
            return 0;
        }
        return profit;
    }
};