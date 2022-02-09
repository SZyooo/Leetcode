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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        ListNode* first,* second;
        first = head;
        second = head;
        int gap = 0;
        ListNode* count = head;
        int n = 0;
        while(count!=nullptr)
        {
            count=count->next;
            n ++;
        }
        k %= n;
        while(gap != k)
        {
            second = second->next;
            gap ++;
        }
        while(second->next!=nullptr)
        {
            second = second->next;
            first = first->next;
        }
        second->next = head;
        ListNode* result = first->next;
        first->next = nullptr;
        return result;
    }
};