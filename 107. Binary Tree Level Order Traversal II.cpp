class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        stack<TreeNode*> stk;
        TreeNode* side = root;
        TreeNode* nextSide = nullptr;
        while(!que.empty())
        {
            TreeNode* front = que.front();
            que.pop();
            stk.push(front);
            if(front->right)
                nextSide = front->right;
            if(front->left)
                nextSide = front->left;
            if(front->right)
                que.push(front->right);
            if(front->left)
                que.push(front->left);
            if(front == side)
            {
                side = nextSide;
                nextSide = nullptr;
                stk.push(nullptr);
            }
        }
        vector<int> aLine;
        if(!stk.top())
            stk.pop();
        while(!stk.empty())
        {
            if(stk.top()==nullptr)
            {
                ans.push_back(aLine);
                vector<int> empty;
                aLine.swap(empty);
            }
            else 
                aLine.push_back(stk.top()->val);
            stk.pop();
        }
        if(aLine.size() > 0)
            ans.push_back(aLine);
        return ans;
        
    }
};