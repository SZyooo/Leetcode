class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int up = 1,left = 0,down = 0,right = 0;
        int size_x = matrix[0].size();
        int size_y = matrix.size();
        int size = size_x*size_y;
        int x = 0,y = 0;
        enum direction{L,D,R,U};
        direction d = R;
        for(int i=0;i<size;i++)
        {
            res.push_back(matrix[y][x]);
            switch(d){
                case R:
                    x ++;
                    if(x == size_x - right)
                    {
                        x --;
                        y ++;
                        right ++;
                        d = D;
                    }
                    break;
                case D:
                    y ++;
                    if(y == size_y - down)
                    {
                        y--;
                        x--;
                        down ++;
                        d = L;
                    }
                    break;
                case L:
                    x --;
                    if(x == left - 1)
                    {
                        x ++;
                        y --;
                        left ++;
                        d = U;
                    }
                    break;
                case U:
                    y --;
                    if(y == up - 1)
                    {
                        y ++;
                        x ++;
                        up ++;
                        d = R;
                    }
                    break;
            }
        }
        return res;
    }
};
