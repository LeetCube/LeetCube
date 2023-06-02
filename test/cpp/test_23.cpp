#include "../../src/cpp/code_23.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<int>> lists_input = input["lists"].get<vector<vector<int>>>();
    vector<int> expected = output.get<vector<int>>();

    vector<ListNode*> lists;

    for (auto l : lists_input) {
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        for (int i = 0; i < (int) l.size(); i++) {
            if (!head) head = curr = new ListNode(l[i]);
            else {
                curr->next = new ListNode(l[i]);
                curr = curr->next;
            }
        }
        lists.push_back(head);
    }

    ListNode* curr = sol.mergeKLists(lists);

    vector<int> result;
    while (curr) {
        ListNode *tmp = curr->next;
        result.push_back(curr->val);
        delete curr;
        curr = tmp;
    }

    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_23.json");
}