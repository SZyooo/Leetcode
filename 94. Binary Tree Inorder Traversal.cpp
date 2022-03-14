/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> values;
        if(root == nullptr)
            return values;
        else{
            stk.push(root);
            TreeNode* curNode = stk.top();
            while(curNode->left)
            {
                stk.push(curNode->left);
                curNode=curNode->left;
            }
            while(stk.empty()==false)
            {
                TreeNode* top = stk.top();
                stk.pop();
                values.push_back(top->val);
                if(top->right)
                {
                    stk.push(top->right);
                    TreeNode* _top = stk.top();
                    while(_top->left)
                    {
                        stk.push(_top->left);
                        _top=_top->left;
                    }
                }
            }
        }
        return values;
    }
};