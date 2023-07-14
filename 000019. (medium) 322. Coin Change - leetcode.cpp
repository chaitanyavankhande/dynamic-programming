
// https://leetcode.com/problems/coin-change/

/* solution 3: memoization */
class Solution {
    int solve(vector<int>&coins, int amount, int n, vector<vector<int>> &dp) {

        if(amount == 0) return 0;
        if(n == 0) return INT_MAX;
        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = INT_MAX;
        if(amount >= coins[n-1]) pick = solve(coins, amount - coins[n-1], n, dp);
        if(pick != INT_MAX) pick += 1;
        int notPick = solve(coins, amount, n-1, dp);
        int ans = min(pick, notPick);
        
        return dp[n][amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n, dp);
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};

/* solution 4: recursion */
class Solution {
    int solve(vector<int>&coins, int amount, int n) {

        if(amount == 0) return 0;
        if(n == 0) return INT_MAX;
        int pick = INT_MAX;
        if(amount >= coins[n-1]) pick = solve(coins, amount - coins[n-1], n);
        if(pick != INT_MAX) pick += 1;
        int notPick = solve(coins, amount, n-1);
        int ans = min(pick, notPick);
        
        return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(coins, amount, n);
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};
