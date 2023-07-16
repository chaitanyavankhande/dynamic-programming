

// https://www.codingninjas.com/studio/problems/minimum-coins_982764


// all the below solutions are giving TLE on code studio platform => 10/11 test cases passed
#include <vector>
#include<limits.h> 

/* solution 1: tabulation space optimized */
int minimumCoins(int amount)
{
    int coins[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    vector<int> current(amount+1, INT_MAX), previous(amount+1, INT_MAX);
    previous[0] = 0;
    for(int i=1; i<=n; i++) {
        current[0] = 0;
        for(int j=1; j<=amount; j++) {
            int pick = INT_MAX;
            if(j >= coins[i-1]) {
                pick = current[j-coins[i-1]];
                if(pick != INT_MAX) pick += 1;
            }
            int notPick = previous[j];
            current[j] = min(pick, notPick);  
        }
        previous = current;
    }
    return previous[amount];
}


/* solution 2: tabulation */
int minimumCoins(int amount)
{
    int coins[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    vector<vector<int>>tb(n+1, vector<int>(amount+1, INT_MAX));
    tb[0][0] = 0;
    for(int i=1; i<=n; i++) {
        tb[i][0] = 0;
        for(int j=1; j<=amount; j++) {
            int pick = INT_MAX;
            if(j >= coins[i-1]) {
                pick = tb[i][j-coins[i-1]];
                if(pick != INT_MAX) pick += 1;
            }
            int notPick = tb[i-1][j];
            tb[i][j] = min(pick, notPick);  
        }
    }
    return tb[n][amount];
}


/* solution 3: memoization */
int solve(int *coins, int n, int amount, vector<vector<int>>&dp) {
    
    if(amount == 0) return 0;
    if(n == 0) return INT_MAX;
    if(dp[n][amount] != -1) return dp[n][amount];
    int pick = INT_MAX;
    if(amount >= coins[n-1]) {
        pick = solve(coins, n, amount-coins[n-1], dp);
        if(pick != INT_MAX) pick += 1;
    }
    int notPick = solve(coins, n-1, amount, dp);
    return dp[n][amount] = min(pick, notPick);
}

int minimumCoins(int p)
{
    int coins[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    vector<vector<int>>dp(n+1, vector<int>(p+1, -1));
    return solve(coins, 9, p, dp);
}


/* solution 4: recursion */
int solve(int *coins, int n, int amount) {
    
    if(amount == 0) return 0;
    if(n == 0) return INT_MAX;
    int pick = INT_MAX;
    if(amount >= coins[n-1]) {
        pick = solve(coins, n, amount-coins[n-1]);
        if(pick != INT_MAX) pick += 1;
    }
    int notPick = solve(coins, n-1, amount);
    return min(pick, notPick);
}

int minimumCoins(int p)
{
    int coins[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    return solve(coins, 9, p);
}
