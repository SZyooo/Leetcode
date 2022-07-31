class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* node, int preVal){
        int cur_sum = preVal*10 + node->val;
        if(node->left != nullptr){
            dfs(node->left,cur_sum);
        }
        if(node->right!=nullptr){
            dfs(node->right,cur_sum);
        }
        if(node->left == nullptr && node->right == nullptr){
            sum += cur_sum;
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};