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

        // reverse the k nodes
        
        ListNode * curr = head;
        auto next_group_start = kth->next;
        auto prev = next_group_start;

        while(curr != next_group_start) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(next_group_start, k);

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
