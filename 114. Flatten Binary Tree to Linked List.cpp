class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curNode = root;
        while(curNode)
        {
            if(curNode->left)
            {
                TreeNode *tNode = curNode->left;
                while(tNode->right)
                    tNode=tNode->right;
                tNode->right = curNode->right;
                tNode = curNode->left;
                curNode->right = tNode;
                curNode->left = nullptr;
                curNode = tNode;
            }
            else{
                while(curNode && !curNode->left)
                    curNode=curNode->right;
            }
        }
    }
};