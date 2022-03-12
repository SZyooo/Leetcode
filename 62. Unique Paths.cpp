class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> line;
        line.resize(n,0);
        vector<vector<int>> mat;
        mat.resize(m,line);
        mat[0][0] = 1;
        for(int l=0;l < m;l++)
        {
            for(int c = 0; c<n;c++)
            {
                if(l == 0 && c == 0)
                {
                    continue;
                }
                if(l-1>=0)
                    mat[l][c] += mat[l-1][c];
                if(c-1>=0)
                    mat[l][c] += mat[l][c-1];
            }
        }
        return mat[m-1][n-1];
    }
};