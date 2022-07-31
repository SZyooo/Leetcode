class Solution {
public:
    vector<vector<bool>> isPalindrome;
    int len;
    vector<string> cur_set;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        len = s.length();
        isPalindrome.resize(len,vector<bool>(len));
        for(int j=0;j<len;j++)
        {
            for(int i=len-1;i>=0;i--)
            {
                if(i==j)
                    isPalindrome[j][i] = true;
                else{
                    if(s[i]!=s[j])
                        isPalindrome[j][i] = false;
                    else{
                        if(i > j)
                            isPalindrome[j][i] = false;
                        else if(i == j-1)
                            isPalindrome[j][i] = true;
                        else
                            isPalindrome[j][i] = isPalindrome[j-1][i+1];
                    }
                }
            }
        }
        dfs(s,0);
        return res;
    }
    void dfs(const string& s, int idx)
    {
        if(idx == len){
            res.push_back(cur_set);
            return;
        }
        for(int i= idx;i<len;i++)
        {
            if(isPalindrome[i][idx])
            {
                cur_set.push_back(s.substr(idx,i-idx+1));
                dfs(s,i+1);
                cur_set.pop_back();
            }
        }
    }
};