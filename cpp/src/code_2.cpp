// 2. Add Two Numbers (Medium)

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
        You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

        You may assume the two numbers do not contain any leading zero, except the number 0 itself.

        @pre The number of nodes in each linked list is in the range [1, 100].
        @pre 0 <= Node.val <= 9
        @pre It is guaranteed that the list represents a number that does not have leading zeros.
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;

        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            curr->next = new ListNode(carry % 10);
            curr = curr->next;
            carry /= 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};