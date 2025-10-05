class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; ++i) kth = kth->next;
            if (!kth) break; 

            ListNode* groupStart = groupPrev->next;
            ListNode* groupNext  = kth->next;

            // in-place reversal 
            ListNode* prev = groupNext;
            ListNode* curr = groupStart;
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            groupPrev->next = prev;
            groupPrev = groupStart; // tail of reversed block for next iteration
        }

        return dummy.next;
    }
};
