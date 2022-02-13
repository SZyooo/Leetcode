class Solution {
public:
    char getChar(char c){
        if(c == '.')
            return '.';
        else if(c <= '9' && c >= '0')
            return 'd';
        else if(c == '+' || c == '-')
            return 's';
        else if(c == 'e' || c == 'E')
            return 'e';
        else return 'x';
    }
    
    bool isDecimal(string& s)
    {
        bool hasDot = false;
        for(int i=0;i<s.length();i++)
        {
            char c = getChar(s[i]);
            if(c == 'x')
                return false;
            else if(c == 'e')
                return false;
            else if(c == 's')
            {
                if(i != 0)
                    return false;
                if(s.length()==1)
                    return false;
            }
            else if(c == '.')
            {
                if(hasDot)
                    return false;
                if(i == 0)
                {
                    if(s.length() == 1 || getChar(s[i+1]) != 'd')
                        return false;
                }
                else if(i > 1 && i < s.length()-1)
                {
                    if(getChar(s[i-1])!='d' || getChar(s[i+1])!='d')
                        return false;
                }
                else if(i == s.length()-1)
                {
                    if(s.length()==1 || getChar(s[i-1])!='d')
                        return false;
                }
                hasDot = true;
            }
        }
        return true;
    }
    bool isInteger(string& s)
    {
        for(int i=0; i<s.length(); i++)
        {
            char ch = getChar(s[i]);
            if(ch == 'x')
                return false;
            else if(ch == 'e')
                return false;
            else if(ch == '.')
                return false;
            else if(ch == 's')
            {
                if(i != 0 || s.length() == 1)
                    return false;
            }
        }
        return true;
    }
    
    bool isNumber(string s) {
        int idx = s.length();
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'E'||s[i] == 'e')
            {
                idx = i;
                break;
            }
        }
        if(idx == 0 || idx == s.length()-1)
            return false;
        string pre = s.substr(0,idx);
        if(isDecimal(pre)==false)
            return false;
        if(idx!=s.length())
        {
            string post = s.substr(idx+1,s.length() - idx);
            if(isInteger(post)==false)
                return false;
        }
        return true;
    }
};