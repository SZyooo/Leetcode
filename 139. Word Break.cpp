class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        vector<bool> vec(s.length(),false);
        for(int i=0;i<s.length();i++){
            for(int j=0;j<=i;j++){
                string rStr = s.substr(j,i-j+1);
                if(j == 0){
                    vec[i] = set.find(rStr)!=set.end();
                }
                else{
                    vec[i] = set.find(rStr)!=set.end() && vec[j-1];
                }
                if(vec[i])
                    break;
            }
        }
        return vec[s.length()-1];
    }
};