class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_max = 0;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            if(i + nums[i] >= cur_max)
            {
                cur_max = i + nums[i];
            }
            if(i == cur_max && cur_max < size - 1)
            {
                return false;
            }
            if(cur_max >= size-1)
                return true;
        }
        return false;
    }
};
