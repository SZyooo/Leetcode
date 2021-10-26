#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m.insert(pair<char, int>(s[i], 1));
                if (max == 0) max = 1;
            }
            else {
                m[s[i]] ++;
                if (m[s[i]] > max) {
                    max = m[s[i]];
                }
            }
        }
        vector<set<char>> bucket(max);
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            bucket[it->second-1].insert(it->first);
        }
        string answer = "";
        for (int i = 1; i <= bucket.size();i++) {
            for (auto it = bucket[i-1].begin(); it != bucket[i-1].end(); it++) {
                string _s;
                for (int j = 0; j < i; j++) {
                    _s += *it;
                }
                answer = _s + answer;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    string _s = "dabc";
    cout << s.frequencySort(_s);
}

