
// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471

#include<vector>
/* solution 1: tabulation space optimized */
long countWaysToMakeChange(int *coins, int n, int amount)
{
    //Write your code here
    vector<long>current(amount+1, 0), previous(amount+1, 0);
    previous[0] = 1;
    for(int i=1; i<=n; i++) {
        current[0] = 1;
        for(int j=1; j<=amount; j++) {
            long pick = 0;
            if(j >= coins[i-1]) pick = current[j-coins[i-1]];
            long notPick = previous[j];      
            current[j] = pick + notPick;        
        }
        previous = current;
    }
    return previous[amount];
}

/* solution 2: tabulation */
long countWaysToMakeChange(int *coins, int n, int amount)
{
    //Write your code here
    vector<vector<long>> tb(n+1, vector<long>(amount+1, 0));
    tb[0][0] = 1;
    for(int i=1; i<=n; i++) {
        tb[i][0] = 1;
        for(int j=1; j<=amount; j++) {
            long pick = 0;
            if(j >= coins[i-1]) pick = tb[i][j-coins[i-1]];
            long notPick = tb[i-1][j];
                
            tb[i][j] = pick + notPick;        
        }
    }
    return tb[n][amount];
}


/* solution 3: memoization */
long solve(int *coins, int amount, int n, vector<vector<long>> &dp) {

    if(amount == 0) return 1;
    if(n == 0) return 0;
    if(dp[n][amount] != -1) return dp[n][amount];
    long pick = 0;
    if(amount >= coins[n-1]) pick = solve(coins, amount - coins[n-1], n, dp);
    long notPick = solve(coins, amount, n-1, dp);
        
    return dp[n][amount] = pick + notPick;
}

long countWaysToMakeChange(int *coins, int n, int amount)
{
    //Write your code here
    vector<vector<long>> dp(n+1, vector<long>(amount+1, -1));
    return solve(coins, amount, n, dp);
}


/* solution 4: recursion */ 
long solve(int *coins, int amount, int n) {

    if(amount == 0) return 1;
    if(n == 0) return 0;
    long pick = 0;
    if(amount >= coins[n-1]) pick = solve(coins, amount - coins[n-1], n);
    long notPick = solve(coins, amount, n-1);
        
    return pick + notPick;
}

long countWaysToMakeChange(int *coins, int n, int amount)
{
    //Write your code here
    return solve(coins, amount, n);
}

