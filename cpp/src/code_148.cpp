// 148. Sort List (Medium)

#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* split(ListNode* head, int k) {
        for (int i = 1; head && i < k; ++i) head = head->next;

        if (!head) return nullptr;
        ListNode* next = head->next;
        head->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* left, ListNode* right, ListNode* head) {
        ListNode* curr = head;

        while (left && right) {
            if (left->val > right->val) {
                curr->next = right;
                right = right->next;
            } else {
                curr->next = left;
                left = left->next;
            }

            curr = curr->next;
        }

        curr->next = max(left, right);

        while (curr->next) curr = curr->next;

        return curr;
    }

public:
    /**
        Given the head of a linked list, return the list after sorting it in ascending order.

        @pre The number of nodes in the list is in the range [0, 5 * 10^4].
        @pre -10^5 <= Node.val <= 10^5
    */
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int length = 0;

        for (ListNode* curr = head; curr; curr = curr->next) ++length;

        ListNode dummy(0, head);

        for (int step = 1; step < length; step *= 2) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);
                tail = merge(left, right, tail);
            }
        }

        return dummy.next;
    }
};