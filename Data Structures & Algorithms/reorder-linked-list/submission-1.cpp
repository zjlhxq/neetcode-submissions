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
        reorder(head, head);
    }

private:
    ListNode* reorder(ListNode* left, ListNode* right) {
        if(right == nullptr) return left;

        left = reorder(left, right->next);
        if(left == nullptr) return nullptr;

        if(left == right || left->next == right) {
            right->next = nullptr;
            return nullptr;
        }

        auto next = left->next;
        left->next = right;
        right->next = next;

        return next;
    }

};
