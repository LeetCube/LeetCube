#include <vector>

#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_148.cpp"

void clear(ListNode*& head) {
    if (!head) return;

    clear(head->next);
    delete head;
    head = nullptr;
}

bool is_equal(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return true;
    if (!l1 || !l2) return false;

    return l1->val == l2->val && is_equal(l1->next, l2->next);
}

ListNode* from_array(const vector<int>& arr, size_t idx) {
    if (idx >= arr.size()) return nullptr;

    return new ListNode(arr[idx], from_array(arr, idx + 1));
}

void test(Solution& sol, const json& input, const json& output) {
    ListNode* head = from_array(input["head"].get<vector<int>>(), 0);
    ListNode* expected = from_array(output.get<vector<int>>(), 0);
    ListNode* result = sol.sortList(head);
    CHECK_UNARY(is_equal(expected, result));
    clear(expected);
    clear(result);
}

TEST_CASE("") {
    TEST("test/test_json/test_148.json");
}