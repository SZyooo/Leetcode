#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	bool sign = dividend>=0 && divisor>=0 || dividend <0 && divisor<0;
    	if(dividend > 0) dividend = 0 - dividend;
    	if(divisor > 0) divisor = 0 - divisor;
    	int o_divisor = divisor;
    	int d_increment = divisor;
    	int res = 0;
    	int r_increment = -1;
    	while(divisor >= dividend)
    	{
    		//res += r_increment;//有可能overflow
    		if(res < -2147483648 - r_increment)
    		{
    			break;
    		}
    		else res += r_increment;
    		if(divisor < -2147483648 - d_increment)
    		{
    			if(d_increment!=o_divisor)
    			{
    				d_increment = o_divisor;
    				r_increment = -1;
    				//divisor += o_divisor; 有可能会overflow
    				//如果overflow了肯定不能再增长了
    				if(divisor < -2147483648 - d_increment)
    				{
    					break;
    				}
    				else{
    					divisor += d_increment;
    				}
    			}
    			else
    			{
    				//如果已经是最低增量了，则直接break
    				break;
    			}
    		}
    		else{
    			//d_increment += d_increment; 有可能overflow
    			if(d_increment < -2147483648 - d_increment)
    			{
    				//如果overflow了，则：
    				//将增量重新设置为初始的divisor
    				//将r_increment设置为-1
    				d_increment = o_divisor;
    				r_increment = -1;
    			}
    			else
    			{
    				d_increment += d_increment;
    				r_increment += r_increment;
    			}
    			if(divisor>= dividend - d_increment)
    			{
    				//这里不会overflow
    				divisor += d_increment;
    			}
    			else
    			{
    				d_increment = o_divisor;
    				r_increment = -1;
    				//divisor += d_increment;有可能overflow
    				if(divisor < -2147483648 - d_increment)
    				{
    					//overflow了，则直接break
    					break;
    				}
    				divisor += d_increment;
    			}
    		}
    	}
    	return sign?(res == -2147483648?2147483647:-res):res;
    }
};
int main()
{
	cout << Solution().divide(2147483647,2);
}