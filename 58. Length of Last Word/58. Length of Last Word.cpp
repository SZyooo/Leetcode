class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool isSpace = true;
        for(int i=s.length() - 1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                if(isSpace)
                {
                    isSpace = false;
                }
                len ++;
            }
            else
            {
                if(!isSpace)
                {
                    return len;
                }
            }
        }
        return len;
    }
};
