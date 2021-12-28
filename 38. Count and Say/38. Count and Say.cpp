class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        else {
            string last = countAndSay(n-1);
            string ans;
            char cur = last[0];
            int num = 1;
            for(int i=1;i<=last.length();i++)
            {
                if(i == last.length())
                {
                    ans += to_string(num) + cur;
                }
                else if(last[i] == cur) 
                    num ++;
                else{
                    ans += to_string(num) + cur;
                    cur = last[i];
                    num = 1;
                }
            }
            return ans;
        }
    }
};