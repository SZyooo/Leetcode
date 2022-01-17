class Solution {
public:
    inline bool check(vector<string>& board, int x, int y)
    {
        int size = board.size();
        for(int i=0;i<size;i++)
        {
            if(board[i][y] == 'Q' || board[x][i] == 'Q')
                return false;
        }
        int _x, _y;
        auto init = [&_x,&_y,x,y]{_x = x ;_y = y;};
        init();
        while(_x >= 0 && _y >=0)
        {
            if(board[_x--][_y--] == 'Q')
                return false;
        }
        init();
        while(_x>=0 && _y < size)
        {
            if(board[_x--][_y++] == 'Q')
                return false;
        }
        init();
        while(_x < size && _y >= 0)
        {
            if(board[_x++][_y--] == 'Q')
                return false;
        }
        init();
        while(_x < size && _y < size)
        {
            if(board[_x++][_y++] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> results;
    void recur(vector<string>& board,int row)
    {
        int size = board.size();
        for(int i=0;i<size;i++)
        {
            if(check(board,row,i))
            {
                board[row][i] = 'Q';
                if(row == board.size() - 1)
                {
                    results.push_back(board);
                }
                else
                {
                    recur(board, row+1);
                }
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string> board;
        board.resize(n,str);
        recur(board,0);
        return results;
    }
};