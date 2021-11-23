#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct Record
{
    string s;
    int left_parenthese_left;
    int expected_right_parenthese;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<Record> _stack;
        _stack.push({"(",n-1,1});
        while(_stack.empty()==false)
        {
            Record r = _stack.top();
            _stack.pop();
            if(r.left_parenthese_left == 0)
            {
                r.s += ")";
                r.expected_right_parenthese --;
                if(r.s.length() == 2*n)
                {
                    res.push_back(r.s);
                }
                else _stack.push(r);
            }
            else{
                if(r.expected_right_parenthese == 0)
                {
                    r.s += "(";
                    r.expected_right_parenthese ++;
                    r.left_parenthese_left --;
                    _stack.push(r);
                }
                else{
                    Record _r = r;
                    _r.s += "(";
                    _r.expected_right_parenthese ++;
                    _r.left_parenthese_left --;
                    r.s += ")";
                    r.expected_right_parenthese --;
                    _stack.push(r);
                    _stack.push(_r);
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<string> res = Solution().generateParenthesis(4);
    for(int i=0;i<res.size();i++){
        cout << res[i]<<endl;
    }
}