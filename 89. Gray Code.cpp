class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i=0;i<n;i++)
        {
            size_t size = res.size();
            for(int j=size-1;j>=0;j--)
            {
                int value = res[j]|(1<<i);
                res.push_back(value);
            }
        }
        return res;
    }
};