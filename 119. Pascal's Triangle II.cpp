class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        for(int i=1;i<rowIndex+1;i++)
        {
            //odd
            if(i%2 == 0)
            {
                int mid = i/2;
                int mid_stable = mid;
                while(mid>0)
                {
                    ans[mid] = ans[mid] + ans[mid-1];
                    int dis = mid_stable-mid;
                    ans[mid_stable + dis] = ans[mid]; 
                    mid --;
                }
            }
            //even
            else{
                int mid = i/2;
                int dis = 0;
                while(mid - dis > 0)
                {
                    ans[mid-dis] = ans[mid-dis] + ans[mid-dis-1];
                    ans[mid + dis + 1] = ans[mid-dis];
                    dis++;
                }
            }
        }
        return ans;
    }
};