class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_benefit = 0;
        int pre = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] > prices[i-1])
            {
                max_benefit += prices[i] - prices[i-1];
            }
        }
        return max_benefit;
    }
};