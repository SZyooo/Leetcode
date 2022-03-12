class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int w = board[0].size(),h = board.size();
        function<bool(int,int,int)> func;
        func = [&func,&board,&word,&h,&w](int idx,int x,int y)->bool
        {
            if(idx == word.length())
                return true;
            bool subRes = false;
            if(x - 1 >=0 && board[x-1][y] == word[idx])
            {
                char c = board[x-1][y];
                board[x-1][y] = '#';
                subRes |= func(idx+1,x-1,y);
                if(subRes)
                    return true;
                board[x-1][y] = c;
            }
            if(x + 1 < h && board[x+1][y] == word[idx])
            {
                char c = board[x+1][y];
                board[x+1][y] = '#';
                subRes |= func(idx+1,x+1,y);
                if(subRes)
                    return true;
                board[x+1][y] = c;
            }
            if(y - 1 >=0 && board[x][y-1] == word[idx])
            {
                char c = board[x][y - 1];
                board[x][y - 1] = '#';
                subRes |= func(idx+1,x,y-1);
                if(subRes)
                    return true;
                board[x][y - 1] = c;
            }
            if(y + 1 < w && board[x][y + 1] == word[idx])
            {
                char c = board[x][y + 1];
                board[x][y + 1] = '#';
                subRes |= func(idx+1,x,y + 1);
                if(subRes)
                    return true;
                board[x][y + 1] = c;
            }
            return subRes;
        };
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(board[i][j] == word[0])
                {
                    char c=board[i][j];
                    board[i][j] = '#';
                    if(func(1,i,j))
                        return true;
                    board[i][j] = c;
                }
            }
        }
        return false;
    }
};