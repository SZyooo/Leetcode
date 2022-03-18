class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr)
        {
            if(q==nullptr)
                return true;
            else
                return false;
        }
        else{
            if(q ==nullptr)
                return false;
            else{
                if(p->val != q->val)
                    return false;
                else{
                    if(isSameTree(p->left,q->left)==false)
                        return false;
                    else if(isSameTree(p->right,q->right) == false)
                        return false;
                    else 
                        return true;
                }
            }
        }
    }
};