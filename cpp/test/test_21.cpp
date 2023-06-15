#include <vector>

#include "../src/code_21.cpp"
#include "cpp_deps/boilerplate.hpp"

namespace {
ListNode* from_array(const std::vector<int>& arr, std::size_t idx) {
    if (idx >= arr.size()) { return nullptr; }
    return new ListNode(arr[idx], from_array(arr, idx + 1));
}

void clear(ListNode*& head) noexcept {
    if (!head) { return; }
    clear(head->next);
    delete head;
    head = nullptr;
}

bool is_equivalent(const std::vector<int>& list_as_vec, ListNode* list) noexcept {
    for (const auto val : list_as_vec) {
        if (list == nullptr) { return false; }
        if (list->val != val) { return false; }
        list = list->next;
    }
    return list == nullptr;
}
}  // namespace

void test(Solution& sol, const json& input, const json& output) {
    std::vector<ListNode> list1_buff{};
    std::vector<ListNode> list2_buff{};
    auto* list1 = from_array(input["list1"].get<std::vector<int>>(), 0);
    auto* list2 = from_array(input["list2"].get<std::vector<int>>(), 0);

    const auto expected = output.get<std::vector<int>>();
    auto* result = sol.mergeTwoLists(list1, list2);

    CHECK(is_equivalent(expected, result) == true);
    clear(result);
}

TEST_CASE("") {
    TEST(21);
}