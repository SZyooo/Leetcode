#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string answer;
        int interval = (numRows-1)*2;
        for (int i = 0; i < numRows; i++)
        {
            int k = i;
            if (k < s.length())
            {
                int j = 0;
                int w;
                while ((w = k + (j++) * interval) < s.length() )
                {
                    answer += s[w];
                    if (i < numRows - 1 && i > 0)
                    {
                        int post = (numRows - 1 - i) * 2;
                        if (w + post < s.length())
                        {
                            answer += s[w + post];
                        }
                    }
                }
            }
        }
        return answer;
    } 
};
int main()
{
    string s("a");
    cout << Solution().convert(s, 1);
}