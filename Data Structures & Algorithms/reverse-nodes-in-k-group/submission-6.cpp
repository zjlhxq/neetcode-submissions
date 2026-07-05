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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto kth = getKth(head, k);
        if(!kth) {
            return head;
        }
        
        auto next_group = kth->next;

        auto newHead = reverseKGroup(kth->next, k);

        auto curr = head;
        auto prev = newHead;
        while (curr != next_group) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

private:
    ListNode* getKth(ListNode* start, int k) {
        while( start && k > 1) {
            start = start->next;
            k --;
        }
        return start;
    }
};