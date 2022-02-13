class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        int wid = obstacleGrid[0].size();
        int hei = obstacleGrid.size();
        vector<int> line;
        line.resize(wid,0);
        vector<vector<int>> mat;
        mat.resize(hei,line);
        mat[0][0] = 1;
        for(int i=0;i < hei ;i++)
        {
            for(int j=0;j<wid;j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    mat[i][j] = 0;
                }
                else{
                    if(i-1>=0)
                        mat[i][j] += mat[i-1][j];
                    if(j-1>=0)
                        mat[i][j] += mat[i][j-1];
                }
            }
        }
        return mat[hei-1][wid-1];
    }
};