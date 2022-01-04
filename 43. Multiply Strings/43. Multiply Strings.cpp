class Solution {
public:
    inline string add(string num1, string num2)
    {
        int idx1 = num1.length() - 1;
        int idx2 = num2.length() - 1;
        string res;
        int overflow = 0;
        while (idx1 >= 0 || idx2 >= 0)
        {
            int n1 = idx1 >= 0 ? num1[idx1] - '0' : 0;
            int n2 = idx2 >= 0 ? num2[idx2] - '0' : 0;
            int sum = n1 + n2 + overflow;
            res += '0' + (sum % 10);
            overflow = sum / 10;
            idx1--;
            idx2--;
        }
        if (overflow > 0)
            res += '0' + overflow;
        if (res.length() == 0)
        {
            res += "0";
            return res;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        string res("0");
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            int n1 = num1[i] - '0';
            if (n1 == 0)
            {
                continue;
            }
            int overflow = 0;
            string cur_res;
            for (int j = num2.length() - 1; j >= 0; j -- )
            {
                int n2 = num2[j] - '0';
                int sum = n1 * n2 + overflow;
                cur_res += '0' + sum % 10;
                overflow = sum / 10;
            }
            if (overflow != 0)
            {
                cur_res += '0' + overflow;
            }
            reverse(cur_res.begin(), cur_res.end());
            for (int k = i; k < num1.length() - 1 && cur_res[0]!='0'; k++) {
                cur_res += "0";
            }
            res = add(res, cur_res);
        }
        return res;
    }
};