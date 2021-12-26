struct label{
    set<int> col,row,block;
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,label> _map;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char c = board[i][j];
                if(c != '.')
                {
                    int val = c - '0';
                    auto it = _map.begin();
                    if((it = _map.find(val)) != _map.end())
                    {
                        if( it->second.col.count(i)!=0 
                         || it->second.row.count(j)!=0
                         || it->second.block.count((i/3)*3+(j/3)))
                        {
                               return false;
                        }
                        else
                        {
                            it->second.col.insert(i);
                            it->second.row.insert(j);
                            it->second.block.insert((i/3)*3+(j/3));
                        }
                    }
                    else
                    {
                        set<int> c,r,b;
                        c.insert(i);
                        r.insert(j);
                        b.insert((i/3)*3+(j/3));
                        label lb{c,r,b};
                        _map.insert(pair<int,label>(val,lb));
                    }
                }
            }
        }
        return true;
    }
};