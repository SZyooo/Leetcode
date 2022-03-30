class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_cost = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int benefit = prices[i] - min_cost;
            if(benefit > ans)
                ans = benefit;
            if(prices[i] < min_cost)
                min_cost = prices[i];
        }
        return ans;
    }
};