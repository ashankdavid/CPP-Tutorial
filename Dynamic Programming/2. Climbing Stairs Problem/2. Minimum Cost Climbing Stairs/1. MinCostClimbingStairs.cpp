// Problem Statement 746 LeetCode - https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Normal Recursion!

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

    int minCostClimbingStairs(vector<int>& cost) {
        // lets take out n first!
        int n = cost.size();
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};

// Here code will be accepted but we will exceed time limit!!(TLE), soo now we will have to add memoization!! check next code!