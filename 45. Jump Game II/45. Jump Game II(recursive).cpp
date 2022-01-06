class Solution {
public:
    vector<int> records;
    int recursive(vector<int>& nums, int position)
    {
        if(position == nums.size()-1)
            return 0;
        if(nums[position] + position >= nums.size() - 1)
            return 1;
        else if(nums[position] == 0)
            return INT_MAX;
        int minNextIndex = INT_MAX;
        for(int i=1;i<=nums[position];i++)
        {
            int min;
            if(records[position + i] != -1)
            {
                min = records[position + i];
            }
            else
            {
                min = recursive(nums,position + i);
            }
            if(min < minNextIndex)
                minNextIndex = min;
        }
        if(minNextIndex == INT_MAX)
        {
            records[position] = INT_MAX;
            return INT_MAX;
        }
        records[position] = minNextIndex + 1;
        return minNextIndex + 1;
    }
    int jump(vector<int>& nums) {
        records.resize(nums.size(),-1);
        return recursive(nums,0);
    }
};