/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        unordered_map<Node*,Node*> traversed_nodes;
        queue<Node*> que;
        Node* root = new Node(node->val,node->neighbors);
        que.push(root);
        traversed_nodes.insert({node,root});
        while(que.empty() == false){
            Node* tNode = que.front();
            que.pop();
            for(int i=0;i<tNode->neighbors.size();i++){
                Node* neighbor = tNode->neighbors[i];
                if(traversed_nodes.find(neighbor)==traversed_nodes.end()){
                    Node* nNode = new Node(neighbor->val,neighbor->neighbors);
                    traversed_nodes.insert({neighbor,nNode});
                    tNode->neighbors[i] = nNode;
                    que.push(nNode);
                }
                else{
                    tNode->neighbors[i] = traversed_nodes[neighbor];
                }
            }
        }
        return root;
    }
};