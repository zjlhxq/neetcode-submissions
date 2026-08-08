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
        ListNode dummy(0, head);
        ListNode* prev_group_tail = &dummy;

        while(true) {
            auto kth = prev_group_tail;
            for(int i=0; i<k; i++) {
                kth = kth->next;
                if(kth == nullptr) {
                    return dummy.next;
                }
            }

            auto group_tail = prev_group_tail->next;
            auto group_next = kth->next;

            ListNode* prev = nullptr;
            auto current = group_tail;
            while(current != group_next) {
                auto next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            prev_group_tail->next = prev; // connect the previous group to the current group
            group_tail->next = group_next; // connect the current group to the next group
            prev_group_tail = group_tail; // reset prev_group_tail
            
        }

        return dummy.next;
    }

};