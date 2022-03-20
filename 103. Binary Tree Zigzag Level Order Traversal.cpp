class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        deque<TreeNode*> dq;
        dq.push_front(root);
        TreeNode* curSideNode = root;
        TreeNode* nextLevelSideNode = nullptr;
        bool left = false;
        vector<int> aLine;
        while(!dq.empty())
        {
            TreeNode* curNode = nullptr;
            if(!left)
            {
                TreeNode* front = dq.front();
                dq.pop_front();
                curNode = front;
                aLine.push_back(front->val);
                if(front->left)
                    dq.push_back(front->left);
                if(front->right)
                    dq.push_back(front->right);
                if(!nextLevelSideNode)
                {
                    if(front->right)
                        nextLevelSideNode = front->right;
                    if(front->left)
                        nextLevelSideNode = front->left;
                }
            }
            else{
                TreeNode* back = dq.back();
                dq.pop_back();
                curNode = back;
                aLine.push_back(back->val);
                if(back->right)
                {
                    dq.push_front(back->right);
                }
                if(back->left)
                {
                    dq.push_front(back->left);
                }
                if(!nextLevelSideNode)
                {
                    if(back->left)
                        nextLevelSideNode = back->left;
                    if(back->right)
                        nextLevelSideNode = back->right;
                }
            }
            if(curNode == curSideNode)
            {
                curSideNode = nextLevelSideNode;
                nextLevelSideNode = nullptr;
                ans.push_back(aLine);
                vector<int> empty;
                aLine.swap(empty);
                left = !left;
            }
        }
        return ans;
    }
};