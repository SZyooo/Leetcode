class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        list<int> arr;
        for(int i=0;i<n;i++)
            arr.push_back(i+1);
        function<vector<vector<int>>(list<int>&,int)> recur; 
        recur = [&recur](list<int>& ar,int num)->vector<vector<int>>
        {
            vector<vector<int>> ans;
            if(num == 1)
            {
                for(int val:ar)
                {
                    ans.push_back({val});
                }
                return ans;
            }
            for(auto iter = ar.begin();iter!=ar.end();iter ++)
            {
                int number = *iter;
                iter = ar.erase(iter);
                iter --;
                list<int> copy(ar.begin(),ar.end());
                vector<vector<int>> subSet = recur(copy,num - 1);
                for(auto v:subSet)
                {
                    v.push_back(number);
                    ans.push_back(v);
                }
            }
            return ans;
        };
        return recur(arr,k);
    }
};