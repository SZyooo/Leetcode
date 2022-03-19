class Solution {
public:
    bool isEqual(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr)
        {
            if(right == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else{
            if(right == nullptr)
            {
                return false;
            }
            else{
                if(left->val!=right->val)
                    return false;
                else{
                    return isEqual(left->left,right->right) && isEqual(left->right,right->left);
                }
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left,root->right);
    }
};