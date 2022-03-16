class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> originNodes(n,nullptr);
        vector<int> indices(n,0);
        for(int i=1;i<=n;i++)
        {
            originNodes[i-1] = new TreeNode(i);
            indices[i-1] = 1;
        }
        function<vector<TreeNode*>(int,int)> fun;
        fun = [&indices,&fun,&originNodes](int start,int end)->vector<TreeNode*>
        {
            if(start == end)
            {
                TreeNode* node = new TreeNode(originNodes[start]->val);
                node->left = nullptr;
                node->right = nullptr;
                vector<TreeNode*> roots{node};
                return roots;
            } 
            if(start > end)
            {
                vector<TreeNode*> roots{nullptr};
                return roots;
            }
            else{
                vector<TreeNode*> ans;
                for(int i = start;i<=end;i++)
                {
                    vector<TreeNode*> left = fun(start,i-1);
                    vector<TreeNode*> right = fun(i+1,end);
                    for(auto _left:left)
                    {
                        for(auto _right:right)
                        {
                            TreeNode* root = new TreeNode(originNodes[i]->val);
                            root->left = _left;
                            root->right = _right;
                            ans.push_back(root);
                        }
                    }
                }
                return ans;
            }
        };
        vector<TreeNode*> roots = fun(0,n-1);
        return roots;
    }
};