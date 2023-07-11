
// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
#include <bits/stdc++.h> 
// solution 1: tabulation space optimized
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.    
    vector<bool> previous(k+1, false), current(k+1, false);
    previous[0] = true;
    for(int i=1; i<=n; i++) {
        current[0] = true;
        for(int j=1; j<=k; j++) {
            bool pick = false;
            if(j >= arr[i-1]) pick = previous[j - arr[i-1]];
            bool notPick = previous[j];
            current[j] = pick || notPick;
        }
        previous = current;
    }
    return previous[k];
    
}

/* solution 2: tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> tb(n+1, vector<bool>(k+1, false));
    tb[0][0] = true;
    for(int i=1; i<=n; i++) {
        tb[i][0] = true;
        for(int j=1; j<=k; j++) {
            bool pick = false;
            if(j >= arr[i-1]) pick = tb[i-1][j - arr[i-1]];
            bool notPick = tb[i-1][j];
            tb[i][j] = pick || notPick;
        }
    }
    return tb[n][k];
    
}
*/

/* solution 3: memoization
bool solve(int n, int k, vector<int>&arr, vector<vector<int>> &dp) {
    
    if(k == 0) return true;
    if(n == 0) return false;
    
    bool pick = false;
    if(k >= arr[n-1]) pick = solve(n-1, k - arr[n-1], arr, dp);
    if(pick) return true;
    bool notPick = solve(n-1, k, arr, dp);
    return dp[n][k] = notPick;
    
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return solve(n, k, arr, dp);
}
*/


/* solution 4: recursion
bool solve(int n, int k, vector<int>&arr) {
    
    if(k == 0) return true;
    if(n == 0) return false;
    
    bool pick = false;
    if(k >= arr[n-1]) pick = solve(n-1, k - arr[n-1], arr);
    if(pick) return true;
    bool notPick = solve(n-1, k, arr);
    return notPick;
    
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return solve(n, k, arr);
}
*/
