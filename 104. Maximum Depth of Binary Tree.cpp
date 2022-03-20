class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        else
        {
            int ldepth = maxDepth(root->left);
            int rdepth = maxDepth(root->right);
            return 1 + max(ldepth,rdepth);
        }
    }
};