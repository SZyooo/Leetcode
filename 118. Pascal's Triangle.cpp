class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int> line(i+1,0);
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                    line[j] = 1;
                else{
                    line[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            ans.push_back(line);
        }
        return ans;
    }
};