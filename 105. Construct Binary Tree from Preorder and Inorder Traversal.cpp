class Solution {
public:
    TreeNode* recursive(vector<int>& preorder, int pstart, int pend, vector<int>&inorder,int istart,int iend)
    {
        if(pstart == pend)
        {
            return new TreeNode(preorder[pstart]);
        }
        else{
            TreeNode* root = new TreeNode(preorder[pstart]);
            int left = istart;
            while(preorder[pstart]!=inorder[left])
                left ++;
            if(left!=istart)
            {
                int leftLen = left - istart;
                root->left = recursive(preorder,pstart+1,pstart + leftLen,inorder,istart,istart + leftLen - 1);
            }
            if(left!=iend)
            {
                int rightLen = iend - left;
                root->right = recursive(preorder,pend - rightLen + 1, pend, inorder, left+1,iend);
            }
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursive(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};