class Solution {
public:
    int maxPath(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        else{
            int left = max(maxPath(root->left),0);
            int right = max(maxPath(root->right),0);
            return left > right?max((left + root->val),0):max((right + root->val),0);
        }       
    }
    int _max = INT_MIN;
    void solve(TreeNode* root, int up)
    {
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        int path1 = max(up,0) + root->val + max(left,0);
        int path2 = max(up,0) + root->val + max(right,0);
        int path3 = root->val + max(left,0) + max(right,0);
        int max_path = max(max(path1,path2),path3);
        _max = max(max_path,_max);
        if(root->left)
        {
            int new_up = max(max(right,0) + root->val,max(up,0) + root->val);
            solve(root->left,new_up);
        }
        if(root->right)
        {
            int new_up = max(max(left,0)+root->val,max(up,0)+root->val);
            solve(root->right,new_up);;
        }
    }
    int maxPathSum(TreeNode* root) {
        solve(root,0);
        return _max;
    }
};