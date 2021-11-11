#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Min(int a, int b) {
        return a > b ? b : a;
    }
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int pre = 0, tail = height.size() - 1;
        while (pre < tail)
        {
            int t = Min(height[pre], height[tail]);
            int area = t * abs(pre - tail);
            if (area > max_area)
                max_area = area;
            if (height[pre] < height[tail])
            {
                pre++;
            }
            else {
                tail--;
            }
        }
        return max_area;
    }
};

int main()
{
    vector<int> values = { 4,3,2,1,4 };
    cout << Solution().maxArea(values);
}