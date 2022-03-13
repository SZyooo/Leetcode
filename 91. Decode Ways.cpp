class Solution {
public:
    int numDecodings(string s) {
        set<string> codes;
        for(int i=1;i<=26;i++)
        {
            codes.insert(to_string(i));
        }
        pair<int,int> p(0,0);//single/total
        vector<pair<int,int>> dp(s.length(),{0,0});
        if(s[0] == '0')
            return 0;
        else
        {
            dp[0].first = 1;
            dp[0].second = 1;
        }
        for(int i=1;i<s.length();i++)
        {
            string cur = s.substr(i,1);
            string pre = s.substr(i-1,1);
            string combine = pre+cur;
            if(codes.find(cur)!=codes.end())
            {
                if(codes.find(combine)!=codes.end())
                {
                    dp[i].second =dp[i-1].second - dp[i-1].first + 2 * dp[i-1].first;
                    dp[i].first = dp[i].second - dp[i-1].first;
                }
                else{
                    dp[i].second = dp[i-1].second;
                    dp[i].first = dp[i].second;
                }
            }
            else{
                if(codes.find(combine)!=codes.end())
                {
                    dp[i].second = dp[i-1].first;
                    dp[i].first = 0;
                }
                else{
                    dp[i].first = 0;
                    dp[i].second = 0;
                }
            }
        }
        return dp[s.length()-1].second;
            
    }
};