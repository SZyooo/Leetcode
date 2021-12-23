#include<iostream>
#include<vector>

//二分查找
//虽然数组按照某个pivot旋转了，但是元素仍然有分布规律
//T：lg(n)
//M:O(1) 
using namespace std;
class Solution {
public:
	inline bool between(int n, int end1, int end2)
	{
		if (end1 <= n && n <= end2 || end2 <= n && n <= end1) return true;
		else return false;
	}
	int binarySearch(vector<int>& nums, int start, int end, int target)
	{
		if (start == end) return nums[start] == target ? start : -1;
		if (end == start + 1)
		{
			if (nums[start] == target) return start;
			if (nums[end] == target) return end;
			else return -1;
		}
		int mid = (start + end) / 2;
		if (nums[mid] == target) return mid;
		bool left = between(target, nums[start], nums[mid]);
		bool right = between(target, nums[mid + 1], nums[end]);
		if (left && right)
		{
			if (nums[mid] > nums[end])
			{
				return binarySearch(nums, 0, mid - 1, target);
			}
			else
			{
				return binarySearch(nums, mid + 1, end, target);
			}
		}
		else if (left) return binarySearch(nums, 0, mid - 1, target);
		else if (right) return binarySearch(nums, mid + 1, end, target);
		else
		{
			if (nums[mid] > nums[end])
			{
				return binarySearch(nums, mid+1, end, target);
			}
			else
			{
				return binarySearch(nums, start, mid-1, target);
			}
		}
	}
	int search(vector<int>& nums, int target) {
		return binarySearch(nums, 0, nums.size() - 1, target);
	}
};

int main()
{
	vector<int> test{ 0,1,2,3,4,6,7 };
	cout << Solution().search(test, 4);
}
