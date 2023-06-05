#include <cstddef>
#include <vector>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto dep_graph = create_graph(static_cast<std::size_t>(numCourses), prerequisites);

        for (auto course = 0; course < numCourses; course++) {
            auto res = resolve_dependencies(course, dep_graph);
            if (!res) { return false; }
        }
        return true;
    }

private:
    enum class NodeState { NOT_VISITED, DISCOVERED, COMPLETED };
    struct GraphNode {
        std::vector<int> neighbors{};
        NodeState state{NodeState::NOT_VISITED};
    };

    using CourseGraph = std::vector<GraphNode>;
    CourseGraph create_graph(std::size_t numCourses, const std::vector<std::vector<int>>& prereq_list) {
        CourseGraph res(numCourses, GraphNode());
        for (const auto& prereq : prereq_list) {
            auto course = prereq[0];
            auto dependant = prereq[1];
            res[course].neighbors.emplace_back(dependant);
        }
        return res;
    }

    bool resolve_dependencies(int course, CourseGraph& dep_graph) {
        if (dep_graph[course].state == NodeState::COMPLETED) { return true; }

        if (dep_graph[course].state == NodeState::DISCOVERED) { return false; }

        dep_graph[course].state = NodeState::DISCOVERED;
        for (const auto& dep : dep_graph[course].neighbors) {
            const auto res = resolve_dependencies(dep, dep_graph);
            if (!res) { return false; }
        }
        dep_graph[course].state = NodeState::COMPLETED;
        return true;
    }
};