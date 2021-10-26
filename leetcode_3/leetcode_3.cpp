//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        int proceed;
        ListNode* next1 = l1;
        ListNode* next2 = l2;
        ListNode* res_next = res;
        ListNode* pre = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            int temp_s = 0;
            if (l1 != nullptr) {
                temp_s += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                temp_s += l2->val;
                l2 = l2->next;
            }
            int local_sum = res_next->val + temp_s;
            res_next->val = local_sum % 10;
            res_next->next = new ListNode(local_sum / 10);
            pre = res_next;
            res_next = res_next->next;
        }
        if (res_next->val == 0) {
            delete pre->next;
            pre->next = nullptr;
            res_next = nullptr;
        }
        return res;
    }
};