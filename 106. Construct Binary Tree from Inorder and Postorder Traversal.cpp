class Solution {
public:
    TreeNode* recursive(vector<int>&inorder, int i_start, int i_end, vector<int>&postorder,int p_start,int p_end)
    {
        if(i_start == i_end)
            return new TreeNode(inorder[i_start]);
        else{
            int left = i_start;
            while(inorder[left]!=postorder[p_end])
                left ++;
            TreeNode* root = new TreeNode(postorder[p_end]);
            if(left!=i_start)
            {
                int leftLen = left - i_start;
                root->left = recursive(inorder,i_start,i_start+leftLen-1,postorder,p_start,p_start + leftLen - 1);
            }
            if(left!=i_end)
            {
                int rightLen = i_end - left;
                root->right = recursive(inorder,i_end - rightLen + 1, i_end, postorder,p_end - rightLen, p_end - 1);
            }
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursive(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};