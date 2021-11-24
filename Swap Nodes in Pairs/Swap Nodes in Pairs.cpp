#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(-1,head);
        ListNode* t_head = newHead;
        while(t_head!=nullptr && t_head->next!=nullptr && t_head->next->next!=nullptr)
        {
        	ListNode* t_node = t_head->next->next;
        	t_head->next->next = t_node->next;
        	t_node->next = t_head->next;
        	t_head->next = t_node;
        	t_head = t_head->next->next;
        }
        ListNode* res = newHead->next;
        delete newHead;
        newHead = nullptr;
        return res;
    }
};

int main()
{
	ListNode* head = nullptr;
	ListNode* newHead = Solution().swapPairs(head);
	while(newHead!=nullptr){
		cout << newHead->val << "\t";
		newHead = newHead->next;
	}
}