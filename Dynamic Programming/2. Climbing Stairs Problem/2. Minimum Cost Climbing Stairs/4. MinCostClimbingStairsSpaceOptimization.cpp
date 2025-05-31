// Problem Statement 746 LeetCode - https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Recursion to Top to Bottom DP to bottom up to space optimization
// Now adding Space Optimization!!

class Solution {
public:

    // TC(Solve) -> O(n) 
    // SC(Solve) -> O(1)
    int solve(vector<int>& cost, int n){
        //Step 1
        int prev2 = cost[0];
        int prev1 = cost[1];

        // Step 2
        for(int i=2; i<n; i++){  //O(n) Time
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // lets take out n first!
        int n = cost.size();
        return solve(cost, n);
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

    // Memoization
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

    // Tabulation
    int solve3(vector<int>& cost, int n){
        // Step 1
        vector<int> dp(n+1);
        // Step 2
        dp[0] = cost[0];
        dp[1] = cost[1];
        //Step 3
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }

    // Space Optimization
    int solve4(vector<int>& cost, int n){
        // Step 1
        // vector<int> dp(n+1); Remove this now Step 1
        // Step 2
        // dp[0] = cost[0]; // Replace dp with a variable
        // dp[1] = cost[1]; // Replace dp with a variable
        int prev2 = cost[0];
        int prev1 = cost[1];
        //Step 3
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            // dp[i] = cost[i] + min(dp[i-1], dp[i-2]); remove this now!
            // now add swapping so they move forward
            prev2 = prev1;
            prev1 = curr;
        }

        // return min(dp[n-1], dp[n-2]);
        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // // lets take out n first!
        // int n = cost.size();
        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // return ans;

        // //Adding Memoization!
        // // lets take out n first!
        // int n = cost.size();
        // // Step 1 - adding the dp array
        // vector<int> dp(n+1, -1); 
        // int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        // return ans;

        // // Tabulation!
        // // lets take out n first!
        // int n = cost.size();
        // return solve3(cost, n);

        // Space Optimization!
        int n = cost.size();
        return solve4(cost, n);
    }
};

*/