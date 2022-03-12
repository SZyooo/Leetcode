class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start + 1 < end)
        {
            int mid = (start + end) / 2;
            if(nums[start] == target)
                return true;
            else if(nums[start] > target)
            {
                if(nums[mid] > nums[start])
                {
                    start = mid + 1;
                }
                else if(nums[mid] < nums[start])
                {
                    if(nums[mid] < target)
                    {
                        start = mid + 1;
                    }
                    else if(nums[mid] > target)
                    {
                        end = mid - 1;
                    }
                    else 
                        return true;
                }
                else{
                    while(nums[start++]!=nums[mid]);
                }
            }
            else
            {
                if(nums[mid] > nums[start])
                {
                    if(nums[mid] > target)
                    {
                        end = mid - 1;
                    }
                    else if(nums[mid] < target)
                    {
                        start = mid + 1;
                    }
                    else
                        return true;
                }
                else if(nums[mid] < nums[start])
                {
                    end = mid - 1;
                }
                else
                {
                    while(nums[start++]!=nums[mid]);
                }
            }
        }
        return nums[start] == target || nums[end] == target;
    }
};