#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multiset<int> s(nums.begin(), nums.end());
        int num;
        for (auto it = s.begin(); it != s.end(); it++) {
            int another = target - *it;
            if (another == *it) {
                if (s.count(another) > 1) {
                    num = *it;
                    break;
                }
            }
            else {
                if (s.count(another) > 0) {
                    num = *it;
                    break;
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num || nums[i] == target - num) {
                if (res.size() == 0) {
                    res.push_back(i);
                }
                else {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
int main() {

}