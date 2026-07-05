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
        removeNthFromEndHelper(head, n);
        return head;
    }
private:
    int removeNthFromEndHelper(ListNode*& head, int n) {
        if(head == nullptr) return 0;

        int count = removeNthFromEndHelper(head->next, n) + 1;
        if( count == n) {
            auto temp = head;
            head = head->next;
            delete temp;
        }

        return count;
    }    
};
