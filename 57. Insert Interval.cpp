class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size() == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        bool left = false,right = false;
        if(intervals[0][0]>=newInterval[0])
        {
            res.push_back({newInterval[0],0});
            left = true;
        }
        for(int i=0;i<intervals.size();i++)
        {
            if(!left && newInterval[0] <= intervals[i][1])
            {
                res.push_back({min(newInterval[0],intervals[i][0]),0});
                left = true;
                i--;
                continue;
            }
            if(left && !right && newInterval[1] < intervals[i][0])
            {
                if(i == 0)
                {
                    res[res.size()-1][1] = newInterval[1];
                }
                else{
                    res[res.size()-1][1] = max(newInterval[1],intervals[i-1][1]);
                }
                right = true;
                i--;
                continue;
            }
            if(left == right)
            {
                res.push_back(intervals[i]);
            }
        }
        if(!left)
        {
            res.push_back(newInterval);
        }
        else if(!right)
        {
            res[res.size()-1][1] = max(newInterval[1],intervals[intervals.size()-1][1]);
        }
        return res;
    }
};