class Solution {
public:
    vector<vector<bool>> recordTable;
    void initTable(string s){
        vector<bool> line(s.length(),false);
        recordTable.resize(s.length(),line);
        for(int j=0;j<s.length();j++){
            for(int i=0;i<s.length();i++){
                if(i == j){
                    recordTable[j][i] = true;
                }
                else if(i < j){
                    if(i + 1 == j){
                        recordTable[j][i] = s[j] == s[i];
                    }
                    else
                        recordTable[j][i] = (s[j] == s[i])&&(recordTable[j-1][i+1]);
                }
                else{
                    recordTable[j][i] = false;
                }
            }
        }   
    }
    int minCut(string s) {
        initTable(s);
        vector<int> minCuts(s.length(),0);
        minCuts[0] = 0;
        for(int i=1;i<minCuts.size();i++){
            int min_val = s.length() + 1;
            for(int j=i;j>0;j--){
                if(recordTable[i][0]){
                    min_val = 0;
                    break;
                }
                else if(recordTable[i][j]){
                    if(minCuts[j-1] + 1 < min_val){
                        min_val = minCuts[j-1]+1;
                    }
                }
            }
            minCuts[i] = min_val;
        }
        return minCuts[s.length()-1];
    }
};