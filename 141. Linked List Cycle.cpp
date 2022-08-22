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
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode* slow_node = head;
        ListNode* quick_node = head;
        while(true){
            slow_node = slow_node->next;
            quick_node = quick_node->next;
            if(quick_node == nullptr)
                return false;
            else quick_node = quick_node->next;
            if(quick_node == nullptr){
                return false;
            }
            else if(slow_node == quick_node)
                return true;
        }
    }
};