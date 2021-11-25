#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void swap(int& n1,int& n2)
	{
		n1 = n1^n2;
		n2 = n1^n2;
		n1 = n2^n1;
	}
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
        int waitToConfirm = 0,finding = 1;
        int k = 0;
        while(finding < nums.size())
        {
       		if(nums[finding] == nums[waitToConfirm]) finding++;
       		else
       		{
       			k++;
       			if(finding == waitToConfirm+1)
       			{
       				waitToConfirm ++;
       				finding ++;
       			}
       			else{
       				swap(nums[++waitToConfirm],nums[finding++]);
       			}
       		}
        }
        return k + 1;
    }
};

int main()
{
	vector<int> test{0,0,1,1,1,2,2,3,3,4};
	cout << Solution().removeDuplicates(test)<<endl;
	for(int i=0;i<test.size();i++){
		cout << test[i] << "\t";
	}
}