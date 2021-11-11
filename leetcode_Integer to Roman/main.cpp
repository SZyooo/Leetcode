#include <iostream>
#include <string>

using namespace std;

/*
I:1
V:5
X:10
L:50
C:100
D:500
M:1000

IV:4 IX:9
XL:40 XC:90
CD:400 CM:900
*/

string operator*(const string s, const size_t time)
{
    string result;
    result.reserve(s.length() * time);
    for (int i = 0; i < time; i++)
        result += s;
    return result;
}

class Solution {
public:
    string getRoman(int base,int time)
    {
        if (base == 1000) { return string("M") * time; }
        else if (base == 500) { return string("D") * time; }
        else if (base == 100) { return string("C") * time; }
        else if (base == 50) { return string("L") * time; }
        else if (base == 10) { return string("X") * time; }
        else if (base == 5) { return string("V") * time; }
        else{ return string("I") * time; }
    }
    string intToRoman(int num) {
        string s;
        int base[] = {1000,500,100,50,10,5,1};
        for (int i = 0; i < 7; i++)
        {
            int time = num / base[i];
            num -= time * base[i];
            s += getRoman(base[i], time);
        }
        size_t pos;
        while ((pos = s.find("VIIII"))!=string::npos)
        {
            s.replace(pos, 5, "IX");
        }
        while ((pos = s.find("IIII")) != string::npos)
        {
            s.replace(pos, 4, "IV");
        }

        while ((pos = s.find("LXXXX")) != string::npos)
        {
            s.replace(pos, 5, "XC");
        }
        while ((pos = s.find("XXXX")) != string::npos)
        {
            s.replace(pos, 4, "XL");
        }
        while ((pos = s.find("DCCCC")) != string::npos)
        {
            s.replace(pos, 5, "CM");
        }
        while ((pos = s.find("CCCC")) != string::npos)
        {
            s.replace(pos, 4, "CD");
        }
        return s;
    }
};
int main()
{
    cout << Solution().intToRoman(9) << endl;
}