class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 1)
        {
            res.push_back({nums[0]});
            return res;
        }
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            int val = *it;
            it = nums.erase(it);
            vector<int> copy(nums.begin(),nums.end());
            vector<vector<int>> sub = permute(copy);
            it = nums.insert(it,val);
            for(auto vec : sub)
            {
                vec.insert(vec.begin(),val);
                res.push_back(vec);
            }
        }
        return res;
    }
};