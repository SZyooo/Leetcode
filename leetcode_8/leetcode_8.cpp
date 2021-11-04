
#include <iostream>


class Solution {
public:
    int reverse(int x) {
        bool isMinus = x < 0;
        unsigned int _x = abs(x);
        int maxBase = 1;
        while (_x/maxBase > 9) maxBase *= 10;
        bool willOverflow = (maxBase == 1000000000);
        int sum = 0;
        int base = 1;
        while (maxBase > 1)
        {
            sum += base * (_x / maxBase);
            _x -= _x / maxBase * maxBase;
            maxBase /= 10;
            base *= 10;
        }
        if (willOverflow)
        {
            if (isMinus)
            {
                if (sum > 147483648)
                {
                    if (_x >= 2) return 0;
                }
                else {
                    if (_x > 2) return 0;
                }
            }
            else
            {
                if (sum > 147483647)
                {
                    if (_x >= 2) return 0;
                }
                else {
                    if (_x > 2) return 0;
                }
            }
        }
        sum += _x * base;
        return isMinus ? -sum : sum;
    }
};

int main()
{
    int num1 = -2147483648;
    int num2 = 1234;
    std::cout << Solution().reverse(num2);
}

