#include <vector>

#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_2.cpp"

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
    ListNode* l1 = from_array(input["l1"].get<vector<int>>(), 0);
    ListNode* l2 = from_array(input["l2"].get<vector<int>>(), 0);
    ListNode* expected = from_array(output.get<vector<int>>(), 0);
    ListNode* result = sol.addTwoNumbers(l1, l2);
    CHECK_UNARY(is_equal(expected, result));
    clear(l1);
    clear(l2);
    clear(expected);
    clear(result);
}

TEST_CASE("") {
    TEST("test/test_json/test_2.json");
}