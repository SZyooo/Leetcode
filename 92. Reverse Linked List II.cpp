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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode t_head(0,head);
        ListNode *pre = &t_head,*post = pre->next;
        int cur_pos = 1;
        bool inRange =false;
        while(cur_pos-1!=right)
        {
            if(cur_pos-1 == left)
            {
                inRange = true;              
            }
            if(inRange)
            {
                ListNode* t_pre = pre;
                pre = post;
                post = post->next;
                pre->next = t_pre;
            }
            else{
                pre = post;
                post = post->next;
            }
            cur_pos++;
        }
        ListNode* findPre = &t_head;
        int idx = 0;
        while(idx+1!=left)
        {
            findPre=findPre->next;
            idx++;
        }
        findPre->next->next = post;
        findPre->next = pre;
        if(findPre == &t_head)
        {
            return t_head.next;
        }
        else{
            return head;
        }
    }
};