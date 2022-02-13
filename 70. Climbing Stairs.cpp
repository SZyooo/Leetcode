class Solution {
public:
    int climbStairs(int n) {
        double square_root_5 = pow(5,0.5);
        double fi = (1 + square_root_5)/2;
        return pow(fi,n+1)/square_root_5 + 0.5;
    }
};