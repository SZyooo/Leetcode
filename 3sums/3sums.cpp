#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      if(nums.size()<3)
      	return res;
      set<int> _set;
      sort(nums.begin(), nums.end());
      for(int i=0;i<nums.size()-2;i++){
      	if(_set.count(nums[i]) > 0)
      		continue;
      	_set.insert(nums[i]);
      	int pre = i+1,tail = nums.size()-1;
      	set<int> hasIn;
      	while(pre < tail)
      	{
      		int sum = nums[pre] + nums[tail];
      		if(sum == -nums[i]) 
      		{
      			if(hasIn.count(nums[pre]) > 0)
      			{
      				pre ++;
      				continue;
      			}
      			if(hasIn.count(nums[tail]) > 0)
      			{
      				tail --;
      				continue;
      			}
      			res.push_back(vector<int>{nums[i],nums[pre],nums[tail]});
      			hasIn.insert(nums[pre]);
      			hasIn.insert(nums[tail]);
      			pre ++;
      			tail --;
      		}
      		else if(sum > -nums[i]) 
      			tail--;
      		else 
      			pre ++;

      	}
      }
      return res;
    }
};
int main()
{
	vector<int> test= {-2,0,0,2,2};
	vector<vector<int>> res = Solution().threeSum(test);
	for(int i=0;i<res.size();i++){
		cout << res[i][0] << " "<<res[i][1] << " " << res[i][2]<<endl;
	}
}