struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged{nullptr};
        ListNode* tail{nullptr};
        while (true) {
            auto* next = getNextNode(list1, list2);
            if (!next) { return merged; }
            if (!merged) {
                merged = next;
                tail = next;
            } else {
                tail->next = next;
                tail = tail->next;
            }
        }
    }

private:
    ListNode* getNextNode(ListNode*& list1, ListNode*& list2) {
        if ((list1 == nullptr) && (list2 == nullptr)) { return nullptr; }

        ListNode* next = nullptr;
        if (list1 == nullptr || ((list2 != nullptr) && (list2->val <= list1->val))) {
            next = list2;
            list2 = list2->next;
        } else {
            next = list1;
            list1 = list1->next;
        }
        next->next = nullptr;
        return next;
    }
};