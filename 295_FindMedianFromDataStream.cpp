#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

// Using two heaps
// addNum() TC = O(log n)
// findMedian() TC = O(1)
// SC = O(n)

class MedianFinder {
public:

    // Max Heap stores smaller half of numbers
    priority_queue<int> maxHeap;

    // Min Heap stores larger half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num) {

        // Add number to the correct heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        // Odd number of elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // Even number of elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {

    MedianFinder obj;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers:" << endl;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        // Add number
        obj.addNum(num);

        // Display median after adding each number
        cout << "After adding " << num
             << ", Median = "
             << obj.findMedian() << endl;
    }

    return 0;
}