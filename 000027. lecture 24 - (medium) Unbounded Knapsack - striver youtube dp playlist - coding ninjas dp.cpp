
// https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029

#include <bits/stdc++.h> 

/* solution 1: tabulation space optimized */
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int>current(w+1, 0), previous(w+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            int pick = 0;
            if(j >= weight[i-1]) pick = profit[i-1] + current[j-weight[i-1]];
            int notPick = previous[j];
            current[j] = max(pick, notPick);      
        }
        previous = current;
    }
    return current[w];
}

/* solution 2: tabulation */
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> tb(n+1, vector<int>(w+1, 0));
    for(int i=1; i<=n; i++) {

        for(int j=1; j<=w; j++) {
            int pick = 0;
            if(j >= weight[i-1]) pick = profit[i-1] + tb[i][j-weight[i-1]];
            int notPick = tb[i-1][j];
            tb[i][j] = max(pick, notPick);      
        }
    }
    return tb[n][w];
}


/* solution 3: memoization */
int solve(int n, int w, vector<int>&profit, vector<int>&weight, vector<vector<int>>&dp) {
    if(w == 0) return 0;
    if(n == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    int pick = 0;
    if(w >= weight[n-1]) pick = profit[n-1] + solve(n, w-weight[n-1], profit, weight, dp);
    int notPick = solve(n-1, w, profit, weight, dp);
    return dp[n][w] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    return solve(n, w, profit, weight, dp);
}


/* solution 4: recursion */
int solve(int n, int w, vector<int>&profit, vector<int>&weight) {
    if(w == 0) return 0;
    if(n == 0) return 0;
    int pick = 0;
    if(w >= weight[n-1]) pick = profit[n-1] + solve(n, w-weight[n-1], profit, weight);
    int notPick = solve(n-1, w, profit, weight);
    return max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return solve(n, w, profit, weight);
}
