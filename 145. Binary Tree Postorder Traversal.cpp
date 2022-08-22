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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* tNode = root;
        auto scan = [&res](TreeNode* h)->void{
            TreeNode* head = h;
            TreeNode* preNode = head;
            TreeNode* postNode = preNode->right;
            head->right = nullptr;
            while(postNode){
                TreeNode* nNode = postNode->right;
                postNode->right = preNode;
                preNode = postNode;
                postNode = nNode;
            }
            while(preNode){
                res.push_back(preNode->val);
                TreeNode* nNode = preNode->right;
                preNode->right = postNode;
                postNode = preNode;
                preNode = nNode;
            }
        };
        while(tNode!=nullptr){
            if(tNode->left!=nullptr){
                TreeNode* cNode = tNode;
                tNode=tNode->left;
                while(tNode->right && tNode->right!=cNode){
                    tNode = tNode->right;
                }
                if(tNode->right == nullptr){
                    tNode->right = cNode;
                    tNode = cNode->left;
                }
                else{
                    tNode->right = nullptr;
                    scan(cNode->left);
                    tNode = cNode->right;
                }
            }
            else{
                tNode=tNode->right;
            }
        }
        if(root)
            scan(root);
        return res;
    }
};