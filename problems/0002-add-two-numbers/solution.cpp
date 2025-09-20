#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;      // result will live on l1
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* prev = nullptr; // last processed node
        int carry = 0;

        while (p || q) {
            int v1 = p ? p->val : 0;
            int v2 = q ? q->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            int digit = sum % 10;

            if (p) {              // reuse l1 node when available
                p->val = digit;
                prev = p;
                p = p->next;
            } else {              // l1 exhausted: splice in l2 node
                prev->next = q;
                q->val = digit;
                prev = q;
                q = q->next;
                continue;
            }
            if (q) q = q->next;
        }

        if (carry) prev->next = new ListNode(carry);
        return head;
    }
};
