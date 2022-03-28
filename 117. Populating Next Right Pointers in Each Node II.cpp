class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        queue<Node*> que;
        que.push(root);
        Node *cur_bound = root, *next_bound = nullptr;
        Node *lastNode = nullptr;
        while(!que.empty())
        {
            Node* front = que.front();
            que.pop();
            if(lastNode)
            {
                lastNode->next = front;
                lastNode = front;
            }
            else
                lastNode = front;
            if(front->left)
            {
                next_bound = front->left;
                que.push(front->left);
            }
            if(front->right)
            {
                next_bound = front->right;
                que.push(front->right);
            }
            if(front == cur_bound)
            {
                lastNode = nullptr;
                cur_bound = next_bound;
                next_bound = nullptr;
            }
        }
        return root;
    }
};