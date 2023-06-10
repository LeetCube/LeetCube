#include "../src/code_23.cpp"
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
    vector<ListNode*> lists;
    for (const auto& l : input["lists"].get<vector<vector<int>>>()) lists.push_back(from_array(l, l.size()));

    ListNode* result = sol.mergeKLists(lists);

    vector<int> out = output.get<vector<int>>();
    ListNode* expected = from_array(out, out.size());

    CHECK_UNARY(is_equal(result, expected));

    for (auto* l : lists) clear(l);
    clear(expected);
    clear(result);
}

// asdf
TEST_CASE("") {
    TEST(23);
}