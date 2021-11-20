#include<iostream>
using std::cout;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* newHead(-1,head);
       	int len = 0;
       	ListNode* t_head = newHead;
		while(t_head!=nullptr){
 			t_head = t_head->next;
 			len ++;
       	} 
       	t_head = head;
       	int remain = len;
       	while(remain!=n+1)
       	{
       		t_head = t_head->next;
       		remain --;
       	}
       	ListNode* discardNode = t_head->next;
       	t_head->next = discardNode->next;
       	delete discardNode;
       	discardNode = nullptr;
       	delete newHead;
       	newHead = nullptr;
       	return head;
    }
};

int main()
{

	return 0;
}