class Solution {
public:
    
    string getPermutation(int n, int k) {
        if(n == 1)
            return "1";
        vector<int> amount;
        vector<char> ordered_array;
        amount.resize(n,0);
        ordered_array.resize(n,'/');
        amount[n-1] = 0;
        ordered_array[n-1] = n + '0';
        amount[n-2] = 1;
        ordered_array[n-2] = n - 1 + '0';
        //amount array stores the number of sub-permutations without the index position itself
        //for example, for index = 3, without the third position, there are two permutations (21,12)
        //another example for index = 4, without the forth position, there are six permutations with 3 positions.
        for(int i=n-3;i>=0;i--)
        {
            amount[i] = amount[i+1] * (n - 1 - i);
            ordered_array[i] = (i + 1) + '0';
        }
        function<string(vector<char>&,int,int)> recur;
        recur = [&amount,n,&recur](vector<char>& oa, int remaining, int pos)->string
        {
            string res;
            if(pos == n - 1)
            {
                for(int i=0;i<oa.size();i++)
                {
                    if(oa[i]!='/')
                    {
                        res += oa[i];
                        break;
                    }
                }
                return res;
            }
            int head_index = remaining/amount[pos] + (remaining%amount[pos] == 0?0:1);
            int nth = 0;
            for(int i=0;i<oa.size();i++)
            {
                if(oa[i]!='/')
                {
                    nth ++;
                }
                if(nth == head_index)
                {
                    res += oa[i];
                    oa[i] = '/';
                    break;
                }
            }
            int remain_amount =remaining - (head_index-1)*amount[pos];
            return res + recur(oa,remain_amount, pos+1);
        };
        return recur(ordered_array,k,0);
    }
};