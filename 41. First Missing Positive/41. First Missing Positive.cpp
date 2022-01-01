class Solution {
public:
    void swap(int& n1,int& n2)
    {
    	n1 = n1 ^ n2;
    	n2 = n1 ^ n2;
    	n1 = n1 ^ n2;
    }
    int firstMissingPositive(vector<int>& nums) {
    	for(int i=0;i<nums.size();i++)
    	{
    		if (nums[i] <= nums.size() && nums[i] > 0)
            {
                int n1 = nums[i], n2 = nums[nums[i] - 1];
                swap(n1,n2);
                nums[i] = n1;
                nums[n2-1] = n2;
                if(n1!=n2) i--;
            }
    	}
    	for(int i=0;i<nums.size();i++)
    	{
    		if(nums[i] != i+1)
    		{
    			return i+1;
    		}
    	}
        return nums.size() + 1 ;
    }
};