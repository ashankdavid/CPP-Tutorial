// Problem Statement Link-> https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Recursion Method
#include <bits/stdc++.h> 
int solveRec(vector<int> &num, int x){
    // Base Case
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX;
    
    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = solveRec(num, x-num[i]);
        if(ans!=INT_MAX)
            mini = min(mini, 1+ans);
    }

    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int ans = solveRec(num, x);
    if(ans==INT_MAX)
        return -1;
    return ans;
}

// Here we get TLE, soo now we have to add Memoization!!!