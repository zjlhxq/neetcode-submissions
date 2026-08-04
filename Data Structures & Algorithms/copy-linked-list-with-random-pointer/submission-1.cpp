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
        if(head == nullptr) return nullptr;

        unordered_map<Node*, Node*> node_map;

        // 1st pass: create node map (old -> new)
        Node* current = head;
        while(current != nullptr) {
            node_map[current] = new Node(current->val);
            current = current->next;
        }

        // 2nd pass: connect the pointers(next, random)
        current = head;
        while(current != nullptr) {
            node_map[current]->next = node_map[current->next];
            node_map[current]->random = node_map[current->random];
            current = current->next;
        }

        return node_map[head];
    }

};
