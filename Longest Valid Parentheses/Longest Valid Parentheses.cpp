#include<iostream>
#include<string>
using namespace std;

//动态规划
//T:O(n)
//M:O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0) return 0;
        int* arr = new int[s.length()];//初始化一个数组
        arr[0] = 0;//第一个位置的子串长度为0，因为只有一个，肯定无法组成合格的子串
        for(int arr_idx = 1;arr_idx <s.length();arr_idx++)
        {
        	if(s[arr_idx] == ')')//如果当前字符是‘）’则有可能于前面的某一个‘（’形成匹配
        	{
        		if(s[arr_idx-1] == '('){
        			if(arr_idx>=2)
        				arr[arr_idx] = arr[arr_idx-2] + 2;
        			else arr[arr_idx] = 2;
        		}
        		else{
        			int t = arr[arr_idx-1];
        			int t_idx = arr_idx-1;
        			int sublen = t;
        			while(t > 0)
        			{
        				t_idx -= t;
        				if(t_idx < 0)
        					break;
        				t = arr[t_idx];
        				sublen += t;
        			}
        			if(t_idx <0 || s[t_idx] == ')')
        				arr[arr_idx] = 0;
        			else
        			{
        				if(arr_idx - sublen - 2 >=0) 
        					arr[arr_idx] = arr[arr_idx - sublen -2] + sublen + 2; 
        				else
        					arr[arr_idx] = sublen + 2;
        			}
        		}
        	}
        	else arr[arr_idx] = 0;//如果当前的是‘（’肯定无法与前面的形成匹配
        }
        int max_sub_len = 0;
        for(int arr_i=0;arr_i<s.length();arr_i++)//遍历数组，找出最大的子串
        {
        	if(arr[arr_i] > max_sub_len)
        		max_sub_len = arr[arr_i];
        }
        delete [] arr;//释放空间
        return max_sub_len;
    }
};

int main()
{
	cout << Solution().longestValidParentheses("()()()()(()()())()()())");
}