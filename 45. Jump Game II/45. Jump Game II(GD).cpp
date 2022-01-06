class Solution {
public:
    int jump(vector<int>& nums) {
        int stp = 0,max_len = 0, target = 0;
        for(int i=0;i<nums.size() - 1;i++)
        {
            if(i + nums[i] > max_len)
                max_len = i + nums[i];
            if(i == target)
            {
                stp ++;
                target = max_len;
            }
        }
        return stp;
    }
};