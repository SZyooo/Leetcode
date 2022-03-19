class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        TreeNode *rightMost = root;
        TreeNode *nextLevelRightMost = nullptr;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> currentLevel;
        while(!que.empty())
        {
            TreeNode *front = que.front();
            que.pop();
            if(front->left)
            {
                nextLevelRightMost = front->left;
                que.push(front->left);
            }
            if(front->right)
            {
                nextLevelRightMost = front->right;
                que.push(front->right);
            }
            currentLevel.push_back(front->val);
            if(front == rightMost)
            {
                ans.push_back(currentLevel);
                vector<int> v;
                currentLevel.swap(v);
                rightMost = nextLevelRightMost;
                nextLevelRightMost = nullptr;
            }
        }
        return ans;
    }
};