// 295. Find Median from Data Stream (Hard)

#include <functional>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<>> hi;

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) / 2.0;
    }
};