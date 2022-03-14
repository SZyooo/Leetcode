class Solution {
public:
    
    vector<string> restoreIpAddresses(string s) {
        function<vector<string>(string,int)> recur;
        recur = [&recur](string str,int dotsNum)->vector<string>{
            if(str.length() == 0)
            {
                vector<string> ans;
                return ans;
            }
            if(dotsNum == 0)
            {
                vector<string> ans;
                if(str[0] == '0' && str.length() > 1)
                {
                    return ans;
                }
                int num = 0;
                for(char c:str)
                {
                    num = num*10 + c-'0';
                    if(num > 255)
                        break;
                }
                if(num > 255)
                {
                    return ans;
                }
                else
                    ans.push_back(str);
                return ans;               
            }
            else{
                if(str[0] == '0')
                {
                    vector<string> subSec = recur(str.substr(1),dotsNum-1);
                    for(string& str_:subSec)
                    {
                        str_.insert(0,"0.");
                    }
                    return subSec;
                }
                else{
                    int cur_code = 0;
                    int idx = 0;
                    vector<string> ans;
                    while(idx < str.length()-1)
                    {
                        cur_code = cur_code*10 + str[idx] - '0';
                        if(cur_code > 255)
                            break;
                        vector<string> subsec = recur(str.substr(idx+1),dotsNum - 1);
                        for(string& subStr:subsec)
                        {
                            string head = to_string(cur_code) + ".";
                            subStr.insert(0,head);
                        }
                        ans.insert(ans.end(),subsec.begin(),subsec.end());
                        idx++;
                    }
                    return ans;
                }
            }
        };
        return recur(s,3);
    }
};