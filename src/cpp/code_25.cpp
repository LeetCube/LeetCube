// 25. Reverse Nodes in k-Group (Hard)

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    /**
        Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

        k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

        You may not alter the values in the list's nodes, only nodes themselves may be changed.

        @pre The number of nodes in the list is n.
        @pre 1 <= k <= n <= 5000
        @pre 0 <= Node.val <= 1000
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* before = &dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (true) {
            ListNode* cursor = after;

            for (int i = 0; i < k; ++i) {
                if (!cursor) return dummy.next;
                cursor = cursor->next;
            }

            curr = after;
            prev = before;

            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};