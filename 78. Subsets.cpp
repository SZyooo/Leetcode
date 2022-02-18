class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        function<void(vector<int>&)> recur_fun;
        recur_fun = [&recur_fun,&ans](vector<int>&arr)
        {
            for(int& val:arr)
            {
                if(val == -11)
                    continue;
                int value = val;
                val = -11;
                recur_fun(arr);
                vector<vector<int>> copy = ans;
                for(auto v:copy)
                {
                    v.push_back(value);
                    ans.push_back(v);
                }
            }
        };
        recur_fun(nums);
        return ans;
    }
};