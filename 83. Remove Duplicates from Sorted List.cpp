/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        int cur_val = head->val;
        ListNode* tmp = head;
        while(tmp->next!=nullptr)
        {
            if(tmp->next->val == cur_val)
            {
                ListNode* del = tmp->next;
                tmp->next = tmp->next->next;
                delete del;
            }
            else{
                cur_val = tmp->next->val;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
