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
        Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

        @pre The number of nodes in the list is in the range [0, 300].
        @pre -100 <= Node.val <= 100
        @pre The list is guaranteed to be sorted in ascending order.
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        int val = 0;

        while (head) {
            if (head->next && head->next->val == head->val) {
                val = head->val;

                while (head && head->val == val) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                }

                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }

        return dummy.next;
    }
};