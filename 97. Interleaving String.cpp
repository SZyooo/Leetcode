//dp
//一般思路是用二维数组
//dp[i][j]：i是s1下标，j是s2下标
//dp[i][j]是否是true就看
//1：dp[i-1][j]为true说明s1[0-i-1]和s2[0-j]构成interleaving， 则dp[i][j]就是在这个基础上添加了字符s1【i】
//2：对于若dp[i][j-1]同理


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length()!=s3.length())
            return false;
        vector<bool> line(s2.size()+1,false);
        vector<vector<bool>> dp(s1.size()+1,line);
        dp[0][0] = true;
        for(int i=1;i<=s2.size();i++)
        {
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        }
        for(int i=1;i<=s1.size();i++)
        {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(dp[i-1][j] && (s1[i-1] == s3[i+j-1]))
                {
                    dp[i][j] = true;
                }
                else if(dp[i][j-1] && (s2[j-1] == s3[i+j-1]))
                {
                    dp[i][j] = true;
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};