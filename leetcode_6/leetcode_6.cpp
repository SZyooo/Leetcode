#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        std::pair<size_t, int> result(0,0);//<head,lenth>, e.g.,"aba":<0,1>
        int before, behind ,len;
        float loc;
        bool isInMiddleOfItems = false;
        for (loc =before = behind = 0,
            len = 0; 
            loc < s.length();
            ) {
            if (before < 0 || behind >= s.length() || s[before] != s[behind] ) {
                if (len > result.second) {
                    result.first = before+1;
                    result.second = len;
                }
                loc += 0.5;
                isInMiddleOfItems = !isInMiddleOfItems;
                if(isInMiddleOfItems == false)
                    before = behind = loc / 1;
                else {
                    before = loc / 1;
                    behind = loc / 1 + 1;
                }
                len = 0;
            }
            else{
                len = (behind++) - (before--) + 1;
            }
        }
        return s.substr(result.first,result.second);
    }
};

int main()
{
    string str("babad");
    cout << Solution().longestPalindrome(str);
}