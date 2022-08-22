/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        map<Node*,Node*> o2n;
        map<Node*,Node*> n2o;
        Node* new_head = new Node(head->val);
        Node* temp1 = head,*temp2 = new_head;
        while(temp1->next){
            temp2->next = new Node(temp1->next->val);
            o2n.insert({temp1,temp2});
            n2o.insert({temp2,temp1});
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        o2n.insert({temp1,temp2});
        n2o.insert({temp2,temp1});
        temp2 = new_head;
        while(temp2){
            Node* oRandom = n2o[temp2]->random;
            if(oRandom == nullptr){
                temp2->random = nullptr;
            }
            else{
                temp2->random = o2n[oRandom];
            }
            temp2 = temp2->next;
        }
        return new_head;
    }
};