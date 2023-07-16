
// https://www.codingninjas.com/studio/problems/minimum-elements_3843091

#include <bits/stdc++.h> 
/* solution 1: tabulation space optimized */
int minimumElements(vector<int> &num, int amount)
{
    // Write your code here.
    int n = num.size();
    vector<int> previous(amount+1, INT_MAX), current(amount+1, INT_MAX);
    
    previous[0] = 0;
    for(int i=1; i<=n; i++) {
        current[0] = 0;
        for(int j=1; j<=amount; j++) {
            int pick = INT_MAX;
            if(j >= num[i-1]) {
                pick = current[j-num[i-1]];
                if(pick != INT_MAX) pick += 1;
            }
            int notPick = previous[j];
            current[j] = min(pick, notPick);            
        }
        previous = current;
    }
    
    int ans = previous[amount];
    if(ans == INT_MAX) ans = -1;
    return ans;
}

/* solution 2: tabulation */
int minimumElements(vector<int> &num, int amount)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> tb(n+1, vector<int>(amount+1, INT_MAX));
    
    tb[0][0] = 0;
    for(int i=1; i<=n; i++) {
        tb[i][0] = 0;
        for(int j=1; j<=amount; j++) {
            int pick = INT_MAX;
            if(j >= num[i-1]) {
                pick = tb[i][j-num[i-1]];
                if(pick != INT_MAX) pick += 1;
            }
            int notPick = tb[i-1][j];
            tb[i][j] = min(pick, notPick);            
        }
    }
    
    int ans = tb[n][amount];
    if(ans == INT_MAX) ans = -1;
    return ans;
}


/* solution 3: memoization */
int solve(vector<int>&num, int amount, int n, vector<vector<int>>&dp) {
    if(amount == 0) return 0;
    if(n == 0) return INT_MAX;
    int pick = INT_MAX;
    if(amount >= num[n-1]) {
        pick = solve(num, amount - num[n-1], n, dp);
        if(pick != INT_MAX) pick += 1;
    }
    int notPick = solve(num, amount, n-1, dp);
    return dp[n][amount] = min(pick, notPick);
}

int minimumElements(vector<int> &num, int amount)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    int ans = solve(num, amount, n, dp);
    if(ans == INT_MAX) ans = -1;
    return ans;
}



/* solution 4: recursion */
int solve(vector<int>&num, int amount, int n) {
    if(amount == 0) return 0;
    if(n == 0) return INT_MAX;
    int pick = INT_MAX;
    if(amount >= num[n-1]) {
        pick = solve(num, amount - num[n-1], n);
        if(pick != INT_MAX) pick += 1;
    }
    int notPick = solve(num, amount, n-1);
    return min(pick, notPick);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    int ans = solve(num, x, n);
    if(ans == INT_MAX) ans = -1;
    return ans;
}
