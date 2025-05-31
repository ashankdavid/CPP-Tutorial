#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // Priority queue to store pairs {element, index}
    priority_queue<pair<int, int>> pq;
    vector<int> result;

    // Process first k elements and add to priority queue
    for (int i = 0; i < k; ++i) {
        pq.push({nums[i], i});
    }

    // Add the maximum of the first window
    result.push_back(pq.top().first);

    // Process the remaining elements
    for (int i = k; i < nums.size(); ++i) {
        // Add the next element to the priority queue
        pq.push({nums[i], i});

        // Remove elements that are out of the current window
        while (pq.top().second <= i - k) {
            pq.pop();
        }

        // Add the current maximum to the result
        result.push_back(pq.top().first);
    }

    return result;
}

// Driver code
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum values in each sliding window: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
