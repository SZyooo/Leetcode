

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        size_t len = 0;
        bool isNegative = false, needCharacter = false, needNonZero = false;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (needCharacter == false)
            {
                if (s[i] == ' ') continue;
                else if (s[i] == '-') {
                    isNegative = true;
                    needCharacter = true;
                }
                else if (s[i] == '+') needCharacter = true;
                else if (s[i] <= '9' && s[i] >= '0') {
                    needCharacter = true;
                    result = result + (s[i] - '0');
                    if (s[i] != '0') {
                        needNonZero = true;
                        len++;
                    }
                }
                else break;
            }
            else {
                if (s[i] < '0' || s[i] > '9') break;
                else {
                    if (len == 9)
                    {
                        if (isNegative)
                        {
                            if (result > INT32_MAX / 10)
                            {
                                result = INT32_MIN;
                                return result;
                            }
                            else if (result == INT32_MAX / 10)
                            {
                                if (s[i] >= '8')
                                {
                                    result = INT32_MIN;
                                    return result;
                                }
                                else
                                {
                                    result = result * 10 + (s[i] - '0');
                                    len++;
                                }
                            }
                            else {
                                result = result * 10 + (s[i] - '0');
                                len++;
                            }
                        }
                        else
                        {
                            if (result > INT32_MAX / 10)
                            {
                                result = INT32_MAX;
                                return result;
                            }
                            else if (result == INT32_MAX / 10)
                            {
                                if (s[i] > '7')
                                {
                                    result = INT32_MAX;
                                    return result;
                                }
                                else
                                {
                                    result = result * 10 + (s[i] - '0');
                                    len++;
                                }
                            }
                            else {
                                result = result * 10 + (s[i] - '0');
                                len++;
                            }
                        }
                    }
                    else if (len == 10)
                    {
                        if (s[i] <= '9' && s[i] >= '0')
                        {
                            if (isNegative)
                            {
                                return INT32_MIN;
                            }
                            else return INT32_MAX;
                        }
                        else break;
                    }
                    else
                    {
                        result = result * 10 + (s[i] - '0');
                        if (needNonZero == false)
                        {
                            if (s[i] != '0')
                            {
                                len++;
                                needNonZero = true;
                            }
                        }
                        else len++;
                    }
                }
            }
        }
        if (isNegative) return -result;
        else return result;
    }
};
int main()
{
    string s(" -2147483648");
    cout << Solution().myAtoi(s);
}