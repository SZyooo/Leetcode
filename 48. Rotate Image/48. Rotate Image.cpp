class Solution {
public:
    void recur_rotate(vector<vector<int>>& m, int s_x,int s_y, int width, int height)
    {
        if(width == 1 || width == 0)
        {
            return;
        }
        int tmp;
        int offset = 0;
        for(int i = s_x; i < s_x + width - 1; i ++, offset ++ )
        {
            tmp = m[s_y][i];
            m[s_y][i] = m[s_y + height - 1 - offset][s_y];
            m[s_y + height - 1 - offset][s_y] = m[s_y + height - 1][s_x + width - 1 - offset];
            m[s_y + height - 1][s_x + width - 1 - offset] = m[s_y + offset][s_x + width - 1];
            m[s_y + offset][s_x + width - 1] = tmp;
        }
        recur_rotate(m,s_x + 1, s_y + 1, width - 2, height - 2);
    }
    void rotate(vector<vector<int>>& matrix) {
        recur_rotate(matrix,0,0,matrix.size(),matrix.size());
    }
};