#include<iostream>
#include<vector>

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
	ListNode* merge2Lists(ListNode* list1,ListNode* list2)
	{
		ListNode* l1 = list1,*l2 = list2;
		if(l1 == nullptr) return l2;
		else if(l2 == nullptr) return l1;
		ListNode* res = nullptr, *_res;
		if(l1->val > l2->val)
		{
			_res = res = l2;
			l2 = l2->next;
		}
		else{
			_res = res = l1;
			l1 = l1->next;
		}
		while(l1!=nullptr && l2!= nullptr)
		{
			if(l1->val > l2->val)
			{
				res->next = l2;
				l2 = l2->next;
			}
			else{
				res->next = l1;
				l1 = l1->next;
			}
			res = res->next;
		}
		if(l1!=nullptr)
		{
			res->next = l1;
		}
		else if(l2!=nullptr)
		{
			res->next = l2;
		}
		return _res;
	}

	ListNode* divide_conquer(vector<ListNode*>& lists,int start,int end)
	{
		ListNode* res = nullptr;
		if(start == end)
		{
			return lists[start];
		}
		int mid = (end + start) / 2;
		ListNode* left = divide_conquer(lists,start,mid);
		ListNode* right = divide_conquer(lists,mid+1,end);
		return merge2Lists(left,right);
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size() == 0) return nullptr;
    	return divide_conquer(lists,0,lists.size()-1);
    }
};
int main()
{
	vector<ListNode*> test;
/*    ListNode* l1 = new ListNode(1,new ListNode(4,new ListNode(5,nullptr)));
    ListNode* l2 = new ListNode(1,new ListNode(3,new ListNode(4,nullptr)));
    ListNode* l3 = new ListNode(2,new ListNode(6,nullptr));*/
/*    test.push_back(l1);
    test.push_back(l2);
    test.push_back(l3);*/
    ListNode* res = Solution().mergeKLists(test);
    while(res!=nullptr) {
    	cout << res->val << "\t" << endl;
    	res = res->next;
    }
}
