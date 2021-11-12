#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 201;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < minLen)
                minLen = strs[i].length();
        }
        string res;
        res.reserve(minLen);
        for (int i = 0; i < minLen; i++)
        {
            char c = strs[0][i];
            bool isOver = false;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != c)
                {
                    isOver = true;
                    break;
                }
            }
            if (isOver) break;
            else {
                res += c;
            }
        }
        return res;
    }
};


int main()
{
    return 1;
}