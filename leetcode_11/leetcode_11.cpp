
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        int** dp = new int* [plen + 1];
        for (int i = 0; i < plen + 1; i++) {
            dp[i] = new int[slen + 1];
        }
        dp[0][0] = true;
        for (int i = 1; i < slen + 1; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i < plen + 1; i++) {
            if (p[i-1] == '*')
            {
                dp[i][0] = dp[i - 2][0];
            }
            else {
                dp[i][0] = false;
            }
        }
        for (int i = 1; i < plen + 1; i++) {
            for (int j = 1; j < slen + 1; j++) {
                if (p[i-1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i-1] == '*')
                {
                    if (dp[i - 2][j])
                    {
                        dp[i][j] = true;
                    }
                    else
                        dp[i][j] = (p[i - 2] == '.' || p[i - 2] == s[j - 1]) && dp[i][j-1];
                }
                else {
                    dp[i][j] = (p[i - 1] == s[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        //for (int i = 0; i < plen + 1; i++)
        //{
        //    for (int j = 0; j < slen + 1; j++) {
        //        cout << dp[i][j];
        //    }
        //    cout << endl;
        //}

        bool r = dp[plen][slen];

        for (int i = 0; i < plen + 1; i++) {
            delete [] dp[i];
        }
        delete [] dp;

        return r;
    }
};

int main()
{
    string s("aaaaaab");
    string p("b.*");
    cout << Solution().isMatch(s, p);
}