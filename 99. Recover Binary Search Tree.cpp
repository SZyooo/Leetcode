class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *one = nullptr, *two = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* lastNode = nullptr;
        
        TreeNode* tNode = nullptr;
        while((tNode = stk.top())->left)
        {
            stk.push(tNode->left);
            tNode = tNode->left;
        }
        
        while(stk.empty()==false)
        {
            TreeNode* node = stk.top();
            stk.pop();
            if(lastNode != nullptr)
            {
                if(node->val < lastNode->val)
                {
                    if(one == nullptr)
                    {
                        one = lastNode;
                        two = node;
                    }
                    else{
                        two = node;
                    }
                }
            }
            lastNode = node;
            if(node->right)
            {
                stk.push(node->right);
                while((tNode = stk.top())->left)
                {
                    stk.push(tNode->left);
                    tNode = tNode->left;
                }
            }
        }
        int tempVal = one->val;
        one->val = two->val;
        two->val = tempVal;
    }
};