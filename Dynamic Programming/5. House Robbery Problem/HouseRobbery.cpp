// Problem Link -> https://www.naukri.com/code360/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

long long int solveSpace(vector<int> &nums){
    long long int n = nums.size();
    long long int prev2 = 0;
    long long int prev1 = nums[0];

   for(int i=1; i<n; i++){
    long long int incl = prev2 + nums[i];
    long long int excl = prev1 + 0;

    long long int ans = max(incl, excl);
    prev2 = prev1;
    prev1 = ans;
   } 
   return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();

    if(n==1) // if there is only 1 house!
        return valueInHouse[0];

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i!=n-1)
            first.push_back(valueInHouse[i]);
        if(i!=0)
            second.push_back(valueInHouse[i]);
    }

    return max(solveSpace(first), solveSpace(second));
}