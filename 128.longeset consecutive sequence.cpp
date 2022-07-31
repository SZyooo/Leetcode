class Solution {
public:
    struct aux_data{
      int min,max,len;  
    };
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,aux_data> uset;
        for(int i:nums)
        {
            if(uset.find(i)!=uset.end())
                continue;
            if(uset.find(i-1)!=uset.end())
            {
                if(uset[i-1].max > i)
                    continue;
                if(uset.find(i+1)!=uset.end())
                {
                    if(uset[i+1].min < i)continue;
                    int len = uset[i-1].len + uset[i+1].len + 1;
                    int left_old_len = uset[i-1].len;
                    int right_old_len = uset[i+1].len;
                    uset[uset[i-1].min].max = uset[i+1].max;
                    uset[uset[i-1].min].len = len;
                    uset[uset[i+1].max].min = uset[i-1].min;
                    uset[uset[i+1].max].len = len;
                    if(left_old_len>1)
                    {
                        uset.erase(i-1);
                    }
                    if(right_old_len>1)
                    {
                        uset.erase(i+1);
                    }
                }
                else{
                    int len = uset[i-1].len + 1;
                    int old_len = uset[i-1].len;
                    uset[uset[i-1].min].max = i;
                    uset[uset[i-1].min].len = len;
                    aux_data ad{uset[i-1].min,i,len};
                    uset.insert({i,ad});
                    if(old_len>1)
                        uset.erase(i-1);
                }
            }
            else{
                if(uset.find(i+1)!=uset.end())
                {
                    if(uset[i+1].min < i)continue;
                    int len = uset[i+1].len+1;
                    int old_len = uset[i+1].len;
                    uset[uset[i+1].max].min = i;
                    uset[uset[i+1].max].len = len;
                    aux_data ad{i,uset[i+1].max,len};
                    uset.insert({i,ad});
                    if(old_len > 1)
                        uset.erase(i+1);
                }
                else{
                    uset.insert({i,{i,i,1}});
                }
            }
        }
        int max = 0;
        for(auto it = uset.begin();it!=uset.end();it++)
        {
            if(it->second.len > max)
                max = it->second.len;
        }
        return max;
    }
};