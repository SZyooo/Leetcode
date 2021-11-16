#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string getChar(int number)
	{
		if(number <= 6)
		{

			char c_s1[] = { char('a' + (number-2) * 3 + 0),'\0' };
			string s1(c_s1);
			char c_s2[] = { char('a' + (number-2) * 3 + 1),'\0' };
			string s2(c_s2);
			char c_s3[] = { char('a' + (number-2) * 3 + 2),'\0' };
			string s3(c_s3);
			return s1+s2+s3;
		}
		else if(number == 7)
		{
			return string("pqrs");
		}
		else if(number == 8)
		{
			return string("tuv");
		}
		else
		{
			return string("wxyz");
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		int number = digits[0] - '0';
		if(digits.length() == 0)
			return res;
		else if(digits.length() == 1)
		{
			string ch = getChar(number);
			for(int i=0;i<ch.length();i++){
				char str[] = {ch[i],'\0'};
				res.push_back(string(str));
			}
			return res;
		}
		string _ch = getChar(number);
		string sub_str = digits.substr(1);
		vector<string> sub = letterCombinations(sub_str);
		for(int i=0;i<_ch.length();i++){
			char ch[] = {_ch[i],'\0'};
			string t_s(ch);
			for(int j=0;j<sub.size();j++){
				res.push_back(t_s + sub[j]);
			}
		}
		return res;
	}
};

int main()
{
    vector<string> res = Solution().letterCombinations("7");
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
}