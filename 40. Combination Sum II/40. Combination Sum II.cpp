class Solution {
public:
    vector<vector<int>> fun(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        if(target <=0) 
            return res;
        bool add = false;
        for(auto it = candidates.begin();it!=candidates.end();)
        {
            int val = *it;
            vector<vector<int>> subRes;
            if(val == target && !add)
            {
                add = true;
                res.push_back({target});
            }
            it = candidates.erase(it);
            vector<int> copy = candidates;
            subRes = combinationSum2(copy,target - val);
            for(auto vec:subRes)
            {
                vec.insert(vec.begin(),val);
                res.push_back(vec);
            }
            while (it!=candidates.end() && (*it) == val)
            {
                it = candidates.erase(it);
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return fun(candidates,target);
    }
};