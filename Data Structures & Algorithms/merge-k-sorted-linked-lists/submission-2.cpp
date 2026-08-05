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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return nullptr;

        for(int i=1; i<lists.size(); i++) {
            lists[i] = merge_two_lists(lists[i], lists[i-1]);
        }

        return lists.back();
    }

private:
    ListNode* merge_two_lists(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while( a != nullptr && b != nullptr) {
            if(a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        if( a != nullptr) {
            tail->next = a;
        }

        if ( b != nullptr ) {
            tail->next = b;
        }

        return dummy.next;
    }    
};
