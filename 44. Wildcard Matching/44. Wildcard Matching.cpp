class Solution {
public:
    bool isMatch(string s, string p) {
        string _p;
        bool isStar = false;
        for(int i=0;i<p.length();i++)
        {
            if(p[i]!='*')
            {
                isStar = false;
                _p += p[i];
            }
            else{
                if(!isStar)
                {
                    _p += p[i];
                }
                isStar = true;
            }
        }
        vector<vector<bool>> match;
        vector<bool> temp(s.length() + 1);
        match.resize(_p.length() + 1,temp);
        match[0][0] = true;
        for(int i = 1;i < match.size();i++)
        {
            if(_p[i - 1] == '*')
            {
                int k = i - 1;
                while(k > 0 && _p[k - 1] == '*')
                    k --;
                bool pre_match = false;
                for(int q = 0; q < match[0].size();q++)
                {
                    if(match[k][q]){
                        pre_match = true;
                        break;
                    }
                }
                match[i][0] = pre_match;
            }
            else match[i][0] = false;
        }
        for(int j = 1; j < match[0].size();j++)
        {
            match[0][j] = false;
        }
        for(int i= 1; i<match.size();i++)
        {
            for(int j=1;j<match[0].size();j++)
            {
                if(_p[i - 1] == '*')
                {
                    int k = i - 1;
                    while(k > 0 && _p[k - 1] == '*')
                        k --;
                    bool pre_match = false;
                    for(int q = 0; q < match[0].size();q++)
                    {
                        if(match[k][q]){
                            pre_match = true;
                            break;
                        }
                    }
                    match[i][j] = pre_match;
                }
                else if(_p[i - 1] == '?' || _p[i-1]==s[j-1])
                {
                    int k = i - 1;
                    while(k > 0 && _p[k - 1] == '*')
                        k --;
                    if(i == 1 || k == i - 1)
                    {
                        match[i][j] = match[k][j-1];
                    }
                    else
                    {
                        bool pre_match = false;
                        for(int a = 0 ; a < j; a ++)
                        {
                            if(match[k][a]){
                                pre_match = true;
                                break;
                            }
                        }
                        match[i][j] = pre_match;
                    }
                }
                else
                {
                    match[i][j] = false;
                }
            }
        }
        return match[match.size()-1][match[0].size()-1];
    }
};