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
        ListNode* tHead = new ListNode(101,head), * scanner = head;
        ListNode* pre = tHead;
        int replicate = 101;
        while(scanner!=nullptr)
        {
            if(scanner->val == replicate)
            {
                ListNode* t = scanner;
                pre->next = scanner->next;
                scanner = scanner->next;
                delete t;
            }
            else
            {
                if(scanner->next!=nullptr && scanner->next->val == scanner->val)
                {
                    replicate = scanner->val;
                }
                else
                {
                    pre = scanner;
                    scanner = scanner->next;
                }
            }
        }
        ListNode* ansHead = tHead->next;
        delete tHead;
        return ansHead;
    }
};