class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0,cur_sum = 0;
        int lastHeight = 0;
        int max_height_idx = 0;
        for(int i=0;i<height.size();i++)
        {
            if(height[i] >= lastHeight)
            {
                lastHeight = height[i];
                max_height_idx = i;
                sum += cur_sum;
                cur_sum = 0;
            }
            else
            {
                cur_sum += lastHeight - height[i];
            }
        }
        cur_sum = 0;
        lastHeight = 0;
        for(int i=height.size()-1;i>=max_height_idx;i--)
        {
            if(height[i] >= lastHeight)
            {
                lastHeight = height[i];
                sum += cur_sum;
                cur_sum = 0;
            }
            else
            {
                cur_sum += lastHeight - height[i];
            }
        }
        return sum;
    }
};