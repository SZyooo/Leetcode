class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int mid = target/2;
        vector<vector<int>> res;
        set<int> s(candidates.begin(),candidates.end());
        if(s.find(target)!=s.end())
        {
            res.push_back({target});
        }
        for(int i=1;i<=mid;i++)
        {
            if(s.find(i) == s.end())
                continue;
            vector<vector<int>> left = combinationSum(candidates,i);
            vector<vector<int>> right = combinationSum(candidates,target-i);
            for(int l=0;l<left.size();l++)
            {
                for(int r=0;r<right.size();r++)
                {
                    vector<int> oneRes;
                    oneRes.insert(oneRes.end(),left[l].begin(),left[l].end());
                    oneRes.insert(oneRes.end(),right[r].begin(),right[r].end());
                    res.push_back(oneRes);
                }
            }
        }
        for(auto i = res.begin();i<res.end();i++)
        {
            for(auto j=i+1;j<res.end();j++)
            {
                if(i->size() == j->size())
                {
                    bool equal = true;
                    sort(i->begin(),i->end());
                    sort(j->begin(),j->end());
                    for(int k=0;k<i->size();k++)
                    {
                        if((*i)[k] != (*j)[k])
                            equal = false;
                    }
                    if(equal)
                        j = res.erase(j) - 1;
                }
            }
        }
        return res;
    }
};