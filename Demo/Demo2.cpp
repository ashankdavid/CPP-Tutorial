#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int solve(int nStairs, int i, vector<int> &dp) // i = current stair h
{
    // base case
    if(i == nStairs) {
        return 1; 
    }
    if(i > nStairs) {
        return 0; 
    }
    if(dp[i] != -1) {
        return dp[i]; 
    }
    // Recurrence relation: ya to 1 step ya 2 steps
    dp[i] = solve(nStairs, i + 1, dp) + solve(nStairs, i + 2, dp);
    return dp[i];
}
// memoization wala variable "i".
int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs + 1, -1);
    return solve(nStairs, 0, dp);
}