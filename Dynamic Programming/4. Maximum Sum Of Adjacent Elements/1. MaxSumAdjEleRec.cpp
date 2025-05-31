// Problem Link -> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Recursion

#include <bits/stdc++.h> 
int solve(vector<int> &nums, int n){
    // base case
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
     
    int incl = solve(nums, n-2) + nums[n]; // current ele
    int excl = solve(nums, n-1) + 0;

    return max(incl, excl);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans = solve(nums, n-1);
    return ans;
}

// This will give TLE soo apply memoization!