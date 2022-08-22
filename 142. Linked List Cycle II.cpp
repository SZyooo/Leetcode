/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        ListNode* fast = head, *slow = head;
        while(true){
            fast = fast->next;
            if(fast==nullptr){
                return nullptr;
            }
            fast = fast -> next;
            if(fast == nullptr){
                return nullptr;
            }
            slow = slow->next;
            if(fast == slow){
                ListNode* tNode = head;
                while(tNode!=slow){
                    tNode=tNode->next;
                    slow=slow->next;
                }
                return tNode;
            }
        }
        return nullptr;
    }
};