#include <vector>

#include "../src/code_21.cpp"
#include "cpp_deps/boilerplate.hpp"

namespace {
ListNode* to_list(const std::vector<int>& list_as_vec, std::vector<ListNode>& node_buffer) noexcept {
    node_buffer.resize(list_as_vec.size());
    for (std::size_t i = 0; i < list_as_vec.size(); i++) {
        node_buffer[i].val = list_as_vec[i];
        if (i == (list_as_vec.size() - 1)) {
            node_buffer[i].next = nullptr;
        } else {
            node_buffer[i].next = &node_buffer[i + 1];
        }
    }
    if (list_as_vec.size() == 0) { return nullptr; }
    return &node_buffer[0];
}

bool is_equivalent(const std::vector<int>& list_as_vec, ListNode* list) noexcept {
    for (const auto val : list_as_vec) {
        if (list == nullptr) { return false; }
        if (list->val != val) { return false; }
        list = list->next;
    }
    if (list != nullptr) { return false; }
    return true;
}
}  // namespace

void test(Solution& sol, const json& input, const json& output) {
    std::vector<ListNode> list1_buff{};
    std::vector<ListNode> list2_buff{};
    auto* list1 = to_list(input["list1"].get<std::vector<int>>(), list1_buff);
    auto* list2 = to_list(input["list2"].get<std::vector<int>>(), list2_buff);

    const auto expected = output.get<std::vector<int>>();
    auto* result = sol.mergeTwoLists(list1, list2);

    CHECK(is_equivalent(expected, result) == true);
}

TEST_CASE("") {
    TEST(21);
}