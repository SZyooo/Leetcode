#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums,int start,int end,int target){
        if(start == end)
        {
            if(nums[start] >= target) return start;
            else return start + 1;
        }
        int mid = (start + end) / 2;
        if(nums[mid] >= target)
        {
            return binarySearch(nums,start,mid,target);
        }
        else
        {
            return binarySearch(nums,mid + 1,end,target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};