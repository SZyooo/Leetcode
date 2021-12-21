#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
思路：
从右到左遍历数组a[i]
    从当前被遍历元素右边开始，向右遍历a[j]
    找到离数组右端最近的一个j，用一个pair来保存符合这个条件的i，j
如果找到了，则交换a[i]和a[j]，并且将a[i]右边排序
如果没找到，则排序整个数组 or 倒转整个数组
*/


class Solution {
public:
    void reverse(vector<int>& v,int start,int end)
    {
        int t;
        for(int i=start,j=end;i<j;i++,j--)
        {
            t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    void nextPermutation(vector<int>& nums) {
        pair<int,int> left_right;
        bool assign = false;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j] < nums[i]) 
                {
                    if(!assign)
                    {
                        left_right.first = j;
                        left_right.second = i;
                        assign = true;
                    }
                    else
                    {
                        if(left_right.first < j)
                        {
                            left_right.first = j;
                            left_right.second = i;
                        }
                    }
                }
            }
        }
        if(assign)
        {
            int t = nums[left_right.first];
            nums[left_right.first] = nums[left_right.second];
            nums[left_right.second] = t;
            reverse(nums,left_right.first+1,nums.size()-1);
        }
        else
        {
            reverse(nums,0,nums.size()-1);
        }
    }
};
int main()
{
    vector<int> test = {1,1,5};
    Solution().nextPermutation(test);
    for(int i=0;i<test.size();i++)
        cout << test[i] <<"\t";
}