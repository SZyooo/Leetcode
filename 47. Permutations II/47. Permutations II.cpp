class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<int> has_processed;
        if(nums.size() == 1)
        {
            res.push_back({nums[0]});
            return res;
        }
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            int val = *it;
            if(has_processed.find(val)!=has_processed.end())
            {
                continue;
            }
            it = nums.erase(it);
            vector<int> copy(nums.begin(),nums.end());
            vector<vector<int>> sub = permuteUnique(copy);
            it = nums.insert(it,val);
            for(auto vec : sub)
            {
                vec.insert(vec.begin(),val);
                res.push_back(vec);
            }
            has_processed.insert(val);
        }
        return res;
    }
};