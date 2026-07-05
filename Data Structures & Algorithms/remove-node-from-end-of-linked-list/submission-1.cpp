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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto [count, newHead] = removeNthFromEndHelper(head, nullptr, n);
        return newHead;
    }
private:
    pair<int, ListNode*> removeNthFromEndHelper(ListNode* head, ListNode* prev, int n) {
        if(head == nullptr) return {0, nullptr};

        auto [count, newHead] = removeNthFromEndHelper(head->next, head, n);
        count ++;
        if( count == n) {
            if(prev != nullptr) {
                prev->next = head->next;
            }
            auto nextHead = head->next;
            delete head;
            head = nextHead;
        }

        return {count, head};
    }    
};
