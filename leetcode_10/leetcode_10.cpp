

#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        int sum = 0;
        int minBase = 1, maxBase = 1;
        while (x / maxBase > 9)maxBase *= 10;
        while (minBase < maxBase)
        {
            int t_base = (minBase == 1000000000) ? 0 : 10 * (x / (minBase * 10));
            int left = x / minBase - t_base;
            t_base = (maxBase == 1000000000) ? 0 : 10 * (x / (maxBase * 10));
            int right = x / maxBase - t_base;
            if (left != right)return false;
            minBase *= 10;
            maxBase /= 10;
        }
        return true;
    }
};

int main()
{
    std::cout << Solution().isPalindrome(456654);
}


