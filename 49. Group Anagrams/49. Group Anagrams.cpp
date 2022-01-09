class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<size_t, vector<string>> m;
        hash<string> str_hash;
        for(auto str:strs)
        {
            string s = str;
            sort(s.begin(),s.end());
            size_t val = str_hash(s);
            if(m.find(val)==m.end())
            {
                m.insert(pair<size_t,vector<string>>(val,{str}));
            }
            else{
                m[val].push_back(str);
            }
        }
        vector<vector<string>> res;
        for(auto it = m.begin();it!=m.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};