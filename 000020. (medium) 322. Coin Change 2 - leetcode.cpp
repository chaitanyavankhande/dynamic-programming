
// https://leetcode.com/problems/coin-change-ii

// solution 1: tabulation space optmized
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> tb(n+1, vector<int>(amount+1, 0));
        vector<int> previous(amount+1, 0), current(amount+1, 0);
        previous[0] = 1;
        for(int i=1; i<=n; i++) {
            current[0] = 1;
            for(int j=1; j<=amount; j++) {
                int pick = 0;
                if(j >= coins[i-1]) pick = current[j-coins[i-1]];
                int notPick = previous[j];
                current[j] = pick + notPick;
            }
            previous = current;
        }
        return previous[amount];
    }
};


// solution 2: tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> tb(n+1, vector<int>(amount+1, 0));
        tb[0][0] = 1;
        for(int i=1; i<=n; i++) {
            tb[i][0] = 1;
            for(int j=1; j<=amount; j++) {
                int pick = 0;
                if(j >= coins[i-1]) pick = tb[i][j-coins[i-1]];
                int notPick = tb[i-1][j];
                tb[i][j] = pick + notPick;
            }
        }
        return tb[n][amount];
    }
};

// solution 3: memoization
class Solution {
    int solve(int amount, vector<int>&coins, int n, vector<vector<int>>&dp) {
        if(amount == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = 0;
        if(amount >= coins[n-1]) pick = solve(amount - coins[n-1], coins, n, dp);
        int notPick = solve(amount, coins, n-1, dp);
        return dp[n][amount] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(amount, coins, n, dp);
    }
};

//solution 4: recursion
class Solution {
    int solve(int amount, vector<int>&coins, int n) {
        if(amount == 0) return 1;
        if(n == 0) return 0;
        int pick = 0;
        if(amount >= coins[n-1]) pick = solve(amount - coins[n-1], coins, n);
        int notPick = solve(amount, coins, n-1);
        return pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(amount, coins, n);
    }
};
