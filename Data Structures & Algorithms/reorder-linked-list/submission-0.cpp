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
    void reorderList(ListNode* head) {
        // split the list into two halves using fast/slow pointers
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second_half_head = slow->next;
        slow->next = nullptr;

        // reverse the second half
        ListNode* prev = nullptr;
        ListNode* current = second_half_head;
        while(current != nullptr) {
            auto next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        second_half_head = prev;

        // merge two lists
        ListNode * first = head;
        ListNode * second = second_half_head;
        while(second != nullptr) {
            auto next1 = first->next;
            auto next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};
