class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int carry = 0;
        int cur_sum = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                int bit_value = 1<<j;
                int n1 = (nums[i] & bit_value) != 0?1:0;
                int n2 = (carry & bit_value) != 0?1:0;
                int n3 = (cur_sum & bit_value) != 0 ? 1 : 0;
                if(n1){
                    if(n3){
                        if(n2){
                            cur_sum -= bit_value;
                            carry -= bit_value;
                        }
                        else{
                            carry += bit_value;
                        }
                    }
                    else{
                        cur_sum += bit_value;
                    }
                }
            }
        }
        return cur_sum;
    }
};