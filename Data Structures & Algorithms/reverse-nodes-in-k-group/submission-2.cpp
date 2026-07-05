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
        auto preGroupEnd = &dummy;
        ListNode* groupTail = nullptr;

        while ( true ) {
            groupTail = preGroupEnd;
            // scout for the next group
            for(int i=0; groupTail != nullptr && i<k ; i++) {
                groupTail = groupTail->next;
                if(groupTail == nullptr) {
                    return dummy.next;
                }
            }

            // mark group boundaries
            auto groupStart = preGroupEnd->next;
            auto nextGroupStart = groupTail->next;

            // reverse the group with k nodes
            auto curr = groupStart;
            auto prev = nextGroupStart;
            for (int i=0; i<k; i++) {
                auto next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // relink groups
            preGroupEnd->next = groupTail;
            preGroupEnd = groupStart;

        }
    }
};
