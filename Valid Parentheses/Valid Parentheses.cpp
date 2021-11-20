#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isPair(char c1,char c2)
    {
        if(c1 == '(') return c2==')';
        else if(c1 == '[')return c2 == ']';
        else return c2=='}';
    }
    bool isValid(string s) {
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(stk.size()==0)
            {
                stk.push(s[i]);
            }
            else if(isPair(stk.top(),s[i]))
            {
                stk.pop();
            }
            else
            {
                if(s[i] == '(' || s[i] =='[' || s[i]=='{')
                {
                    stk.push(s[i]);
                }
                else return false;
            } 
        }
        return stk.empty();
    }
};
using std::cout;
int main()
{   
    cout << Solution().isValid("([}}])");
}