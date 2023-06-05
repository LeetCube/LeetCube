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
          Given the head of a linked list, remove the nth node from the end of the list and return its head.

          @pre The number of nodes in the list is sz.
          @pre 1 <= sz <= 30
          @pre 0 <= Node.val <= 100
          @pre 1 <= n <= sz
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // NOLINTBEGIN
        if (!head) return head;

        int num = 0;
        for (ListNode* n = head; n != nullptr; n = n->next) num++;

        if (num == n) {
            ListNode* temp = head->next;
            delete head;
            head = temp;
            return head;
        }

        ListNode* beforeTarget = head;
        for (int i = 1; i < num - n; i++) beforeTarget = beforeTarget->next;

        ListNode* target = beforeTarget->next;
        if (target) beforeTarget->next = target->next;
        delete target;

        return head;
        // NOLINTEND
    }
};
