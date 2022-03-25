class Solution {
public:
    vector<vector<int>> ans;
    void recursive(TreeNode* root, int targetSum, vector<int>& curVec)
    {
        if(root->left)
        {
            curVec.push_back(root->val);
            recursive(root->left,targetSum - root->val,curVec);
            curVec.pop_back();
        }
        if(root->right)
        {
            curVec.push_back(root->val);
            recursive(root->right,targetSum-root->val,curVec);
            curVec.pop_back();
        }
        if(!root->left && !root->right)
        {
            if(root->val == targetSum)
            {
                curVec.push_back(root->val);
                ans.push_back(curVec);
                curVec.pop_back();
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return ans;
        vector<int> line;
        recursive(root,targetSum,line);
        return ans;
    }
};