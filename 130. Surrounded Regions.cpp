class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> que;
        que.push({ i,j });
        int n = 0;
        while (que.empty() == false) {
            auto p = que.front();
            que.pop();
            //cout << "(" << p.first << "," << p.second << ") = " << board[p.first][p.second]<<endl;
            board[p.first][p.second] = 'C';
            if (p.first > 0 && board[p.first - 1][p.second] == 'O') {
                    que.push({p.first - 1,p.second});
                    board[p.first - 1][p.second] = 'C';
            }
            if (p.first < board.size() - 1 && board[p.first + 1][p.second] == 'O') {
                    que.push({ p.first + 1,p.second });
                    board[p.first + 1][p.second] = 'C';
            }
            if (p.second > 0 && board[p.first][p.second - 1] == 'O') {
                    que.push({ p.first,p.second - 1 });
                    board[p.first][p.second - 1] = 'C';
            }
            if (p.second < board[0].size() - 1 && board[p.first][p.second + 1] == 'O') {
                    que.push({ p.first,p.second + 1 });
                    board[p.first][p.second + 1] = 'C';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size()-1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
                else
                    board[i][j] = 'X';
            }
        }
    }
};