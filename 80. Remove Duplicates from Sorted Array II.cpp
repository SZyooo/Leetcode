class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int swapPos = 0, curNum = 100000, show_times = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=curNum)
            {
                curNum = nums[i];
                show_times = 1;
                nums[swapPos++] = nums[i];
                ans ++;
            }
            else{
                show_times ++;
                if(show_times <= 2){
                    nums[swapPos++] = nums[i];
                    ans++;
                }
            }
        }
        return ans;
    }
};