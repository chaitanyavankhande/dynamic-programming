// Frog Jump
// memoization solution
// https://www.codingninjas.com/studio/problems/frog-jump_3621012 

int solve(int n, vector<int>&arr, vector<int>&dp) {
    
    if(n==1) return 0;
    if(n<1) return INT_MAX;

    if(dp[n] != -1) return dp[n];

    int oneJump = abs(arr[n-1] - arr[n-2]) + solve(n-1, arr, dp);
    int twoJump = abs(arr[n-1] - arr[n-3]) + solve(n-2, arr, dp);
    
    if(n-2 >= 1) return dp[n] = min(oneJump, twoJump);
    else return dp[n] = oneJump;
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n+1, -1);
    return solve(n, heights, dp);    
}
