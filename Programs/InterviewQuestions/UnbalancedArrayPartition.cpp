#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rearrangeAndPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = n - 1;
    int sum = 0;

    while (left <= right) {
        if (left == right) {
            sum += nums[left];
        } else {
            sum += nums[left];
            sum += nums[right];
        }
        left++;
        right--;
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxMinSum = rearrangeAndPartition(nums);
    cout << "Maximum sum of minimum elements in subarrays: " << maxMinSum << endl;

    return 0;
}
