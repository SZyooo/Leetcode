#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int head = 0;
        int tail = 0;
        int maxLen = 0;
        int temp_maxlen = 0;
        set<char> _set;
        while (tail < s.length()) {
            if (_set.find(s[tail]) == _set.end()) {
                _set.insert(s[tail++]);
                temp_maxlen++;
            }
            else {
                if (temp_maxlen > maxLen)
                    maxLen = temp_maxlen;
                temp_maxlen = 0;
                while (s[head++] != s[tail]);
                tail = head;
                _set.clear();
            }
        }
        if (temp_maxlen > maxLen)
            maxLen = temp_maxlen;
        return maxLen;
    }
};

int main() {
    string test = "dvabvcdf";
    Solution s;
    cout << s.lengthOfLongestSubstring(test);
}