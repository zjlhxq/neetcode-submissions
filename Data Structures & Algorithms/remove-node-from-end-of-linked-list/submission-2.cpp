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
        
        // count the list
        auto curr = head;
        int count = 0;
        while(curr != nullptr) {
            curr = curr->next;
            count ++;
        }

        // head is to be deleted
        if(count == n) {
            auto newHead = head->next;
            delete head;
            return newHead;
        }

        // remove a non-head node
        ListNode* slow = head;
        
        int steps_to_move = count - n - 1;
        while ( steps_to_move > 0) {
            slow = slow->next;
            steps_to_move --;
        }


        auto toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        return head;
    }
};
