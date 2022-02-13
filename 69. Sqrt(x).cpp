class Solution {
public:
    int mySqrt(int x) {
        long ans = x;
        while(ans*ans > x)
        {
            ans = 0.5f*(ans + x/ans);
        }
        return ans;
    }
};