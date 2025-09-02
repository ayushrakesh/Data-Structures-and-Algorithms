class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int n=prices.size();
        int mini=prices[0];

        for(int i=1;i<n;i++){
            if(prices[i] < mini){
                mini=prices[i];
            }
            res=max(res,prices[i]-mini);
        }
        return res;
    }
};