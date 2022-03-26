class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return nullptr;
        if(root->left)
        {
            Node* left = root->left;
            Node* right = root->right;
            while(left)
            {
                left->next = right;
                left = left->right;
                right = right->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};