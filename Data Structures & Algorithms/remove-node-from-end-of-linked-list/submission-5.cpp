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
        return removeNth(head, n);
    }
private:
    ListNode* removeNth(ListNode* head, int& n) {
        if(head == nullptr) return head;

        head->next = removeNth(head->next, n);
        n --;
        if ( n == 0) {
            return head->next;
        }

        return head;
    }
        
};
