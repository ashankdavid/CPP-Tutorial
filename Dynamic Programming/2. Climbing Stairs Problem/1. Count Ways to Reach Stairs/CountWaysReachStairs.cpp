// Problem Statement - https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

int solve(int nStairs, int i){  // i is curr stair
    //base case
    if(i == nStairs) // if curr is only dist stair
        return 1;

    if(i > nStairs)
        return 0;

    return (solve(nStairs, i+1) + solve(nStairs, i+2));
}

int countDistinctWays(int nStairs) {
    int ans = solve(nStairs, 0);
    return ans;
}
