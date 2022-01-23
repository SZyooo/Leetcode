class Solution {
public:
    bool isOverlap(vector<int>& v1, vector<int>& v2)
    {
        return !(v1[1] < v2[0] || v2[1] < v1[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(auto it = intervals.begin();it!=intervals.end();++it)
        {
            int min = (*it)[0],max = (*it)[1];
            for(auto iter = res.begin();iter!=res.end();){
                if(isOverlap(*it,*iter))
                {
                    if((*iter)[0] < min)
                        min = (*iter)[0];
                    if((*iter)[1] > max)
                        max = (*iter)[1];
                    iter = res.erase(iter);
                }
                else
                    iter ++;
            }
            res.push_back(vector<int>{min,max});
        }
        return res;
    }
};
