class Solution {
public:
    TreeNode* recursive(vector<int>& nums, int begin,int end)
    {
        if(begin == end)
            return new TreeNode(nums[begin]);
        else{
            int len = end - begin + 1;
            int mid = (begin + end)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            if(mid!=begin)
                root->left = recursive(nums,begin,mid-1);
            if(mid!=end)
                root->right = recursive(nums,mid+1,end);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        else
        {
            return recursive(nums,0,nums.size()-1);
        }
    }
};