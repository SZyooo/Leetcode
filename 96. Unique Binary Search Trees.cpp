class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n + 1,1);
        for(int i=2;i<=n;i++)
        {
            int sum = 0;
            for(int j = 1;j<=i;j++)
            {
                sum += v[j-1]*v[i-j];
            }
            v[i] = sum;
        }
        return v[n];
    }
};