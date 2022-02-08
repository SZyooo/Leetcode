class Solution {
public:
    int x_in[4] = {1,0,-1,0};
    int y_in[4] = {0,1,0,-1};
    vector<vector<int>> generateMatrix(int n) {
        vector<int> fill;
        fill.resize(n,0);
        vector<vector<int>> res;
        res.resize(n,fill);
        int x = 0,y = 0;
        int delta = 0;
        int step = n,cur_step = 0;
        int row_turn = 0;
        for(int i=0;i<n*n;i++)
        {
            res[y][x] = i+1;
            cur_step ++;
            if(cur_step == step)
            {
                delta = (delta+1)%4;
                row_turn ++;
                if (row_turn == 3)
                {
                    cur_step = 2;
                }
                else if (row_turn == 4)
                {
                    row_turn = 0;
                    cur_step = 0;
                    step -= 2;
                }
                else cur_step = 1;
            }
            x += x_in[delta];
            y += y_in[delta];
        }
        return res;
    }
};