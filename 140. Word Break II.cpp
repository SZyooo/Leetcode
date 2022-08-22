class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        int len = s.length();
        vector<string> empty;
        vector<vector<string>> res(len,empty);
        string head_char = s.substr(0,1);
        if(set.find(head_char)!=set.end())
            res[0].push_back(head_char);
        for(int i=1;i<len;i++){
            string whole_left = s.substr(0,i+1);
            if(set.find(whole_left)!=set.end()){
                res[i].push_back(whole_left);
            }
            for(int j=i;j>=1;j--){
                string word = s.substr(j,i-j+1);
                if(set.find(word)!=set.end()){
                    for(auto str:res[j-1]){
                        string str_here = str + " " + word; 
                        res[i].push_back(str_here);
                    }
                }
            }
        }
        return res[len-1];
    }
};