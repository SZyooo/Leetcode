class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        std::vector<bool> line(len,false);
        std::vector<vector<bool>> face(len,line);
        std::vector<vector<vector<bool>>> cube (len,face);

        for(int l = 1;l<=len;l++)
        {
            for(int i = 0;i + l <= len; i++)
            {
                for(int j=0; j + l <= len ; j++)
                {
                    if(l == 1)
                    {
                        cube[i][j][l-1] = (s1[i] == s2[j]);
                    }
                    else
                    {
                        for(int q = 1;q < l;q++)
                        {
                            bool res = cube[i][j][q - 1] && cube[i+q][j+q][l- q - 1];
                            res |= cube[i][j + l - q][q - 1] && cube[i + q][j][l-q-1];
                            if(res)
                            {
                                cube[i][j][l-1] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return cube[0][0][len-1];
    }
};
