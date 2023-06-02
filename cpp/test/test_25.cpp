#include <vector>

#include "../src/code_25.cpp"
#include "cpp_deps/boilerplate.hpp"

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
    int k = input["k"].get<int>();
    ListNode* expected = from_array(output.get<vector<int>>(), 0);
    ListNode* result = sol.reverseKGroup(head, k);
    CHECK_UNARY(is_equal(expected, result));
    clear(expected);
    clear(result);
}

TEST_CASE("") {
    TEST("../data/json_testcases/test_25.json");
}