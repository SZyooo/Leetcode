class Solution {
public:
	vector<int> binarySearch(const vector<int>&nums,int start, int end,int target)
	{
		vector<int> ret;
        if(nums.size() == 0)
        {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
		if(start == end)
		{
			if(nums[start] == target)
			{
				ret.push_back(start);
				ret.push_back(end);
			}
			else{
				ret.push_back(-1);
				ret.push_back(-1);
			}
            return ret;
		}
		else
		{
			int mid = (start + end) / 2; 
			vector<int> leftRes = binarySearch(nums,start,mid,target);
			vector<int> rightRes = binarySearch(nums,mid+1,end,target);
			if(leftRes[0] == -1 && rightRes[1] == -1){
				ret.push_back(-1);
				ret.push_back(-1);
				return ret;
			}
			else if(leftRes[0] == -1) return rightRes;
			else if(rightRes[0] == -1) return leftRes;
			else
			{
				ret.push_back(leftRes[0]);
				ret.push_back(rightRes[1]);
				return ret;
			}
		}
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};