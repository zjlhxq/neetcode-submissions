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
        auto groupTail = &dummy;

        while ( true ) {
            groupTail = preGroupEnd;
            for(int i=0; groupTail != nullptr && i<k ; i++) {
                groupTail = groupTail->next;
                if(groupTail == nullptr) {
                    return dummy.next;
                }
            }

            //
            auto groupStart = preGroupEnd->next;
            auto nextGroupStart = groupTail->next;
            auto curr = groupStart;
            auto prev = nextGroupStart;
            for (int i=0; i<k; i++) {
                auto next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            preGroupEnd->next = prev;
            preGroupEnd = groupStart;

        }


    }
};
