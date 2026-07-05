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
        auto kth = getKth(head, k);
        if(!kth) {
            return head;
        }
        

        auto newHead = reverseKGroup(kth->next, k);
        auto curr = head;
        auto prev = newHead;
        int count = k;
        while (count > 0) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count --;
        }

        return prev;
    }

private:
    ListNode* getKth(ListNode* start, int k) {
        int count = 0;
        while( start && k > 1) {
            std::cout << "cout: " << count ++ << std::endl;
            start = start->next;
            k --;
        }
        return start;
    }
};
