class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int start = digits.size() - 1;
        int proceed = 0;
        while(start >= 0 && (proceed = (++digits[start])/10))
        {
            digits[start] = digits[start]%10;
            start -- ;
        }
        if(proceed > 0)
        {
            digits.insert(digits.begin(),proceed);
        }
        return digits;
    }
};
