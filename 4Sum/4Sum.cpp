#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> twoSum(vector<int>& nums,int start,int end,int target)
	{
		vector<vector<int>> res;
		while(start < end)
		{
			int sum = nums[start] + nums[end];
			if(sum == target)
			{
				res.push_back(vector<int>{nums[start++],nums[end--]});
			}
			else if(sum < target)
			{
				start++;
			}
			else{
				end --;
			}
		}
		return res;
	}
	vector<vector<int>> recursiveSum(vector<int>&nums,int start,int end,int target,int k)
	{
		vector<vector<int>> res;
		while(start < end && nums[start+1] == nums[start])start++;
		while(end > start && nums[end-1] == nums[end]) end --;
		if(end - start + 1 < k) return res;
		if(k == 2)
		{
			res = twoSum(nums,start,end,target);
		}
		else{
			for(int i=start ; i <= end-k +1 ;i++){
				vector<vector<int>> subRes = recursiveSum(nums,i+1,end,target - nums[i],k-1);
				for(int j=0;j<subRes.size();j++){
					vector<int> item(k);
					item.push_back(nums[i]);
					item.insert(item.end(),subRes[j].begin(),subRes[j].end());
					res.push_back(item);	
				}
			}
		}
		return res;
	}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	sort(nums.begin(),nums.end());
        return recursiveSum(nums,0,nums.size()-1,target,4);
    }
};

int main()
{
	vector<int> test = { -3,-2,-1,0,0,1,2,3 };
	vector<vector<int>> res = Solution().fourSum(test, 0);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}

}