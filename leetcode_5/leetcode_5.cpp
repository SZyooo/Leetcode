#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int passNum = 0;
        int median[2]{0,0}, loc = 0;
        int arr1_flag = 0;
        int arr2_flag = 0;
        int total_len = nums1.size() + nums2.size();
        if (total_len == 0) return 0;
        nums1.push_back(10e6 + 1);
        nums2.push_back(10e6 + 1);
        for (int i = 0; i < total_len / 2 + 1; i++) {
            if (nums1[arr1_flag] < nums2[arr2_flag]) {
                median[(loc++) % 2] = nums1[arr1_flag++];
            }
            else {
                median[(loc++) % 2] = nums2[arr2_flag++];
            }
        }
        if (total_len % 2 == 0)
            return (median[0] + median[1]) / 2.0f;
        else
            if (total_len / 2 % 2 == 1)
                return median[1];
            else return median[0];
    }
};
int main() {
    vector<int> nums1({ 1,3,6 });
    vector<int> nums2({ 2,3,5 });
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}