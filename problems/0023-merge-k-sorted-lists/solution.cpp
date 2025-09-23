#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list (LeetCode provides this).
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Comparator for the min-heap:
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Min-heap (priority queue) storing pointers to the current head
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto node : lists) {
            if (node) pq.push(node);
        }

        // Dummy node simplifies list construction.
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = cur;

            if (cur->next) {
                pq.push(cur->next);
            }
        }

        // The merged list starts after the dummy node.
        return dummy.next;
    }
};
