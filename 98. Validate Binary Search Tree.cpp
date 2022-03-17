//inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool hasAssign = false;
        int val = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* tNode = nullptr;
        while((tNode = stk.top())->left)
        {
            stk.push(tNode->left);
            tNode=tNode->left;
        }
        while(stk.empty()==false)
        {
            tNode = stk.top();
            stk.pop();
            if(hasAssign)
            {
                if(val >= tNode->val)
                    return false;
            }
            else
            {
                hasAssign = true;
            }
            val = tNode->val;
            if(tNode->right)
            {
                stk.push(tNode->right);
                while((tNode=stk.top())->left)
                {
                    stk.push(tNode->left);
                    tNode=tNode->left;
                }
            }
        }
        return true;
    }
};