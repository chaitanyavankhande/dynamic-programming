
// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
#include <bits/stdc++.h>

// solution 1: tabulation space optimized
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int first=0, second=nums[0], current=nums[0];
    
    for(int i=1; i<n; i++) {
        int pick = nums[i];
        if(i-2 >= 0) pick += first;
        int notPick = second;
        current = max(pick, notPick);

        first = second;
        second = current;
    }
    return current;  
}

/*solution 2: tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>tb(n+1, -1);
    tb[0] = nums[0];
    for(int i=1; i<n; i++) {
        int pick = nums[i];
        if(i-2 >= 0) pick += tb[i-2];
        int notPick = tb[i-1];
        tb[i] = max(pick, notPick);
    }
    return tb[n-1];  
}
*/

/* solution 3: memoization
int solve(int n, vector<int>&nums, vector<int>&dp) {
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n] != -1) return dp[n];
    int pick = nums[n] + solve(n-2, nums, dp);
    int notPick = solve(n-1, nums, dp);
    return dp[n] = max(pick, notPick);
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n, -1);
    return solve(n-1, nums, dp);
}
*/


/*solution 4: recursion
int solve(int n, vector<int>&nums) {
    if(n<0) return 0;
    if(n==0) return nums[0];
    int pick = nums[n] + solve(n-2, nums);
    int notPick = solve(n-1, nums);
    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return solve(n-1, nums);
}
*/
