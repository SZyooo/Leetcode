
//solve sudoku
//stack or recursion
class Solution {
public:
    bool over = false;
    void solveSudoku(vector<vector<char>>& board) {
        int pr = -1, pc = -1;
        for (int r = 0; r < 9; r++)
        {
            bool isBreak = false;
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                {
                    pr = r;
                    pc = c;
                    isBreak = true;
                    break;
                }
            }
            if (isBreak) break;
        }
        if (pc == -1) {
            over = true;
            return;
        }
        set<int> col { 1,2,3,4,5,6,7,8,9 };
        set<int> row{ 1,2,3,4,5,6,7,8,9 };
        set<int> agg{ 1,2,3,4,5,6,7,8,9 };
        for (int i = 0; i < 9; i++)
        {
            if (board[i][pc] != '.')
            {
                int val = board[i][pc] - '0';
                row.erase(val);
            }
            if (board[pr][i] != '.')
            {
                int val = board[pr][i] - '0';
                col.erase(val);
            }
        }
        int block = pr / 3 * 3 + pc / 3;
        int rbegin = block / 3 * 3;
        int cbegin = (block - (block / 3 * 3)) * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char c;
                if ((c = board[rbegin + i][cbegin + j]) != '.')
                {
                    int val = c - '0';
                    agg.erase(val);
                }
            }
        }
        set<int> tempRes;
        set<int> res;
        set_intersection(col.begin(), col.end(), row.begin(), row.end(), inserter(tempRes, tempRes.begin()));
        set_intersection(tempRes.begin(), tempRes.end(), agg.begin(), agg.end(), inserter(res, res.begin()));
        for (auto it = res.begin(); it != res.end(); it++)
        {
            board[pr][pc] = '0' +  *it;
            solveSudoku(board);
            if (over) return;
        }
        board[pr][pc] = '.';
    }
};