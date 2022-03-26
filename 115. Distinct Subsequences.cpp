class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length() == t.length())
            return s==t?1:0;
        vector<unsigned int> line(s.length()+1,0);
        vector<vector<unsigned int>>dp(t.length()+1,line);
        dp[0][0] = 1;
        for(int i=1;i<=s.length();i++)
        {
            dp[0][i] = 1;
        }
        for(int i=1;i<=t.length();i++)
        {
            dp[i][0] = 0;
        }
        for(int i=1;i<=t.length();i++)
        {
            for(int j=1;j<=s.length();j++)
            {
                if(s[j-1] == t[i-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t.length()][s.length()];
    }
};