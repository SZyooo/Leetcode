class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> l2r(prices.size(),0);
        vector<int> r2l(prices.size(),0);
        
        int min = prices[0];
        int p1 = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] - min > p1)
                p1 = prices[i] - min;
            if(min > prices[i])
                min = prices[i];
            l2r[i] = p1;
        }
        int max = *(prices.end()-1);
        int p2 = 0;
        for(int i = prices.size()-2;i>=0;i--){
            if(max - prices[i] > p2)
                p2 = max - prices[i];
            if(max < prices[i])
                max = prices[i];
            r2l[i] = p2;
        }
        int P = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(l2r[i] + r2l[i] > P)
                P = l2r[i] + r2l[i];
        }
        return P;
    }
};