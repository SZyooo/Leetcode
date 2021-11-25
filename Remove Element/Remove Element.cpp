#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = 0, left = nums.size() - 1;
        int k = 0;
        while(right <= left)
        {
        	if(nums[right] == val)
        	{
        		if(nums[left] == val) left --;
        		else
        		{
        			nums[right] = nums[right] ^ nums[left];
        			nums[left] = nums[right] ^ nums[left];
        			nums[right] = nums[left] ^ nums[right];
        			right ++;
        			left --;
        			k++;
        		}
        	}
        	else {
        		right ++;
        		k ++;
        	}
        }
        return k;
    }
};

int main()
{
	vector<int> test{};
	int k = Solution().removeElement(test,2);
	cout << k << endl;
	for(int i=0;i<k;i++){
		cout << test[i] <<"\t";
	}
}