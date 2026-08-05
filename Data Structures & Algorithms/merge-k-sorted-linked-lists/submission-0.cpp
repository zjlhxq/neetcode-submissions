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
        auto cmp = [](ListNode* a, ListNode* b) { return a->val >= b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for(auto cur_list : lists) {
            if(cur_list != nullptr) {
                pq.push(cur_list);
            }
        }

        ListNode dummy;
        ListNode * tail = &dummy; 
        while(! pq.empty()) {
            auto current = pq.top();
            pq.pop();
            tail->next = current;
            if (current->next != nullptr) {
                pq.push(current->next);
            }

            tail = tail->next;
        }

        return dummy.next;
    }
};
