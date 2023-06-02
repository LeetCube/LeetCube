// 23. Merge k Sorted Lists (Hard)

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    struct comp {
        bool operator()(ListNode*& n1, ListNode*& n2) const {
            return n1->val > n2->val;
        }
    };

public:
    /**
     * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
     * Merge all the linked-lists into one sorted linked-list and return it.
     * @pre k == lists.length
     * @pre 0 \<= k \<= 10^4
     * @pre 0 \<= lists[i].length \<= 500
     * @pre -10^4 \<= lists[i][j] \<= 10^4
     * @pre lists[i] is sorted in ascending order.
     * @pre The sum of lists[i].length will not exceed 10^4.
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (auto l : lists)
            if (l) pq.push(l);

        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        while (!pq.empty()) {
            ListNode* entry = pq.top();
            pq.pop();

            if (!head) head = curr = entry;
            else {
                curr->next = entry;
                curr = entry;
            }

            if (entry->next) pq.push(entry->next);
        }

        return head;
    }
};