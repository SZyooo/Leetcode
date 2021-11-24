#include <iostream>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(k <= 1)return head;
        ListNode* dummyNode = new ListNode(-1,head);
        ListNode* res = dummyNode;
        while(true)
        {
        	ListNode* t_node = dummyNode;
        	int pass = 0;
        	bool over = false;
        	while(pass != k )
        	{
        		t_node = t_node->next;
        		if(t_node == nullptr)
        		{
        			over = true;
        			break;
        		} 
        		else{
        			pass ++;
        		}
        	}
        	if(over) break;
        	ListNode* l_node = dummyNode->next;
        	ListNode* r_node = l_node->next;
        	for(int i=0;i<k-2;i++)
        	{
        		ListNode* tnode = r_node->next;
        		r_node->next = l_node;
        		l_node = r_node;
        		r_node = tnode;
        	}
        	dummyNode->next->next = r_node->next;
        	r_node->next = l_node;
        	ListNode* d_next = dummyNode->next;
        	dummyNode->next = r_node;
        	dummyNode = d_next;
        }
        return res->next;
    }
};

int main()
{
	ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,nullptr)))));
	ListNode* res = Solution().reverseKGroup(head,4);
	while(res!=nullptr)
	{
		cout << res->val;
		res = res->next;
	}	
}