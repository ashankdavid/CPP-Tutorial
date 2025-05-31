// Problem Link -> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Tabulation

#include <bits/stdc++.h> 
int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);

   dp[0] = nums[0];

   for(int i=1; i<n; i++){
    int incl = dp[i-2] + nums[i];
    int excl = dp[i-1] + 0;
    dp[i] = max(incl, excl);
   } 
   return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    return solveTab(nums);
}


// Code Backup
/*

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

int solveMem(vector<int> &nums, int n, vector<int> &dp){
    // base case
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
    
    if(dp[n]!=-1)
        return dp[n];

    int incl = solve(nums, n-2) + nums[n]; // current ele
    int excl = solve(nums, n-1) + 0;

    // step 2
    dp[n] = max(incl, excl);
    return dp[n];
}

int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);  // step1

    dp[0] = nums[0]; // step2

    for(int i=1; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;

        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // int n = nums.size();
    // int ans = solve(nums, n-1);
    // return ans;

    // int n = nums.size();
    // // step 1
    // vector<int> dp(n, -1);
    // return solveMem(nums, n-1, dp);

    return solveTab(nums);
}

*/