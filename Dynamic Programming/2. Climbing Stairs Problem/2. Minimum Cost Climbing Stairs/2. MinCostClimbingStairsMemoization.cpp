// Problem Statement 746 LeetCode - https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Recursion to Top to Bottom DP
// Now adding Memoization!!

class Solution {
public:

    // TC(Solve) -> O(n) 
    // SC(Solve) -> O(n) + O(n)
    int solve(vector<int>& cost, int n, vector<int>& dp){ //O(n) Space
        // Base Case also here in every function call we are taking //O(n) Space
        if(n == 0) // maybe u have come from 0th stair
            return cost[0];
        if(n == 1) // maybe u have come from 1st stair
            return cost[1];

        //Step 3
        if(dp[n]!=-1)
            return dp[n];

        // Step 2
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // lets take out n first!
        int n = cost.size();

        // Step 1 - add dp array
        vector<int> dp(n+1, -1);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};

// Now this code will work absolutly fine with all the test cases and TC as well !!


/*
LeetCode Editor! Backup
Currently Saving Originals
class Solution {
public:

    int solve(vector<int>& cost, int n){
        // Base Case
        if(n == 0) // maybe u have come from 0th stair
            return cost[0];
        if(n == 1) // maybe u have come from 1st stair
            return cost[1];

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }

    // Memoization!
    int solve2(vector<int>& cost, int n, vector<int>& dp){
        // Base Case
        if(n == 0) // maybe u have come from 0th stair
            return cost[0];
        if(n == 1) // maybe u have come from 1st stair
            return cost[1];

        // Step 3
        if(dp[n] != -1)
            return dp[n];
        
        //Step 2
        dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // // lets take out n first!
        // int n = cost.size();
        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // return ans;

        //Adding Memoization!
        // lets take out n first!
        int n = cost.size();
        // Step 1 - adding the dp array
        vector<int> dp(n+1, -1); 
        int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return ans;
    }
};

*/