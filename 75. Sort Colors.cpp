class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        while(left < nums.size() && nums[left] == 0)
            left ++;
        while(right >= 0 && nums[right] == 2)
            right --;
        for(int i=left;i <= right;i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = nums[left];
                nums[left] = 0;
                left ++;
                if(i >= left)
                    i--;
            }
            else if(nums[i] == 2)
            {
                nums[i] = nums[right];
                nums[right] = 2;
                right --;
                i--;
            }
        }
    }
};