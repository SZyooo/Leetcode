#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum;
        bool isAssign = false;
        for(int i=0;i<nums.size();i++){
        	int pre = i + 1;
        	int tail = nums.size()-1;
        	while(pre < tail)
        	{
        		int sum = nums[i] + nums[pre] + nums[tail];
        		if(sum == target)
        			return target;
        		if(isAssign == false)
        		{
        			closestSum = sum;
        			isAssign = true;
        		}
        		else if(abs(sum - target) < abs(closestSum - target))
        		{
        			closestSum = sum;
        		}
        		if(sum > target) tail --;
        		else if(sum < target) pre ++;
        	}
        }
        return closestSum;
    }
};
int main()
{
	vector<int> test = {0,0,0};
	cout << Solution().threeSumClosest(test,1);
}