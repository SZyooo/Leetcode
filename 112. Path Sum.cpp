class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        else{
            bool res = false;
            if(root->left)
            {
                res |= hasPathSum(root->left,targetSum - root->val);
            }
            if(root->right)
            {
                res |= hasPathSum(root->right,targetSum - root->val);
            }
            if(!root->left && !root->right)
            {
                return root->val == targetSum;
            }
            return res;
        }
    }
};