class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mins1(triangle.size(),0);
        vector<int> mins2(triangle.size(),0);
        mins1[0] = triangle[0][0];
        vector<int>* cv = &mins2, *lv = &mins1;
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j == 0)
                {
                    (*cv)[j] = (*lv)[j] + triangle[i][j];
                }
                else if(j == triangle[i].size()-1)
                {
                    (*cv)[j] = (*lv)[j-1] + triangle[i][j];
                    auto tp = cv;
                    cv = lv;
                    lv = tp;
                }
                else{
                    int left = (*lv)[j-1] + triangle[i][j];
                    int right = (*lv)[j] + triangle[i][j];
                    (*cv)[j] = left<right?left:right;
                }
            }
        }
        int min = INT_MAX;
        for(int v:(*lv))
        {
            if(v < min)
                min = v;
        }
        return min;
    }
};