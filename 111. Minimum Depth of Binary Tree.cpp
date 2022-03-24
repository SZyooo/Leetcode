class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(root->left==nullptr)
        {
            if(root->right)
                return 1 + minDepth(root->right);
            else return 1;
        }
        else
        {
            if(root->right)
            {
                return 1 + min(minDepth(root->left),minDepth(root->right));
            }
            else
            {
                return 1 + minDepth(root->left);
            }
        }
    }
};