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
        if (head == nullptr) return nullptr;

        if(node_map.contains(head)) return node_map[head];

        Node * copy = new Node(head->val);
        node_map[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }

private:
    unordered_map<Node*, Node*> node_map;
};
