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

        ListNode* fast = head;
        ListNode* slow = head;

        // let fast move n steps
        while(fast != nullptr && n > 0) {
            fast = fast->next;
            n --;
        }
        
        // head needs to be deleted
        if (fast == nullptr) {
            auto temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // let slow join fast until fast reaches the tail
        while( fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        auto to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;

        return head;
    }
        
};
