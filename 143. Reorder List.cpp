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
    void reorderList(ListNode* head) {
        ListNode* slow = head, *quick = head;
        while(true){
            if(quick == nullptr){
                break;
            }
            quick = quick->next;
            if(quick == nullptr){
                break;
            }
            quick = quick->next;
            slow = slow->next;
        }
        if(slow == head){
            return;
        }
        ListNode* tNode = slow->next;
        slow->next = nullptr;
        while(tNode!=nullptr){
            ListNode* pre = slow;
            slow = tNode;
            tNode = tNode->next;
            slow->next = pre;
        }
        ListNode* node1 = head, * node2 = slow;
        while(true){
            tNode = node1->next;
            node1->next = node2;
            node1 = tNode;
            if(node1 == node2){
                node1->next = nullptr;
                break;
            }
            tNode = node2->next;
            node2->next = node1;
            node2 = tNode;
            if(node1 == node2){
                node1->next = nullptr;
                break;
            }
        }
    }
};