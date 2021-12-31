#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	vector<vector<int>> recurSolu(vector<int>& candidates, int target,int minIdx)
	{
		vector<vector<int>> res;
		if(target <= 0) return res;
		for(int candidate : candidates){
			if(candidate < minIdx)
			{
				continue;
			}
			if(target == candidate)
			{
				res.push_back({target});
			} 
			vector<vector<int>> subRes = recurSolu(candidates,target-candidate,candidate);
			for(auto vec: subRes)
			{
				vec.insert(vec.begin(),candidate);
				res.push_back(vec);
			}
		}
		return res;
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		return recurSolu(candidates,target,candidates[0]);
	}
};

int main()
{
	vector<int> test{2,3,6,7};
	int target = 7;
	vector<vector<int>> res = Solution().combinationSum(test,target);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout << res[i][j]<<"\t";
		}
		cout << endl;
	}
}