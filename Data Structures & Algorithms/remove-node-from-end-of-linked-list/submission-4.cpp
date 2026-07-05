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
        ListNode dummy(0, head);
        ListNode * slow = &dummy;
        ListNode * fast = &dummy;

        for(int i=0; i<= n; i++) {
            fast = fast->next;
        }

        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        auto target = slow->next;
        slow->next = target->next;
        delete target;

        return dummy.next;
    }
        
};
