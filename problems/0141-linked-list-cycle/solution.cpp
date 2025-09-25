class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (true) {
            if (slow == fast) return true;
            slow = slow->next;
            if (!fast->next) return false;
            fast = fast->next->next;
            if (!fast || !slow) return false;
        }
    }
};
