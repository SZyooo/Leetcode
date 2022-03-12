class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int a_idx = a.length()-1,b_idx = b.length() - 1;
        while(a_idx >= 0 || b_idx >=0)
        {
            int a_v = a_idx>=0?(a[a_idx]-'0'):0;
            int b_v = b_idx>=0?(b[b_idx]-'0'):0;
            a_idx --;
            b_idx --;
            int sum = (a_v + b_v + carry);
            ans += sum % 2 + '0';
            carry = sum/2;
        }
        if(carry == 1)
        {
            ans += '1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};