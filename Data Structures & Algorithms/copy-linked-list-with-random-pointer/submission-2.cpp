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

        // pass 1: create node copies and interleave them in the list
        Node* current = head;
        while(current != nullptr) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // pass 2: connect randome pointers for the copied nodes
        current = head;
        while(current != nullptr) {
            Node* copy = current->next;
            if(current->random != nullptr) {
                copy->random = current->random->next; 
            }
            current = copy->next;
        }

        // pass 3: separe the original and copied lists
        current = head;
        Node * copy_head = head->next;
        while(current != nullptr) {
            Node * copy = current->next;
            
            current->next = copy->next;
            if(copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            current = current->next;
        }

        return copy_head;

    }

};
