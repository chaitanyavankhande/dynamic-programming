
// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
#include <bits/stdc++.h> 

// solution 1: tabulation space optimized
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<int>previous(m, 0), current(m, 0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) current[j] = grid[i][j];
            else {
                int left = INT_MAX, up = INT_MAX;
                if(j-1 >= 0) left = current[j-1];
                if(i-1 >= 0) up = previous[j];
                current[j] = grid[i][j] + min(left, up);
            }
        }
        previous = current;
    }
    return current[m-1];
}

/* soltuion 2: tabulation
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> tb(n, vector<int>(m, -1));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) tb[i][j] = grid[i][j];
            else {
                int left = INT_MAX, up = INT_MAX;
                if(j-1 >= 0) left = tb[i][j-1];
                if(i-1 >= 0) up = tb[i-1][j];
                tb[i][j] = grid[i][j] + min(left, up);
            }
        }
    }
    return tb[n-1][m-1];
}
*/

/*solution 3: memoization
int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) {
    if(i==0 && j==0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int left = INT_MAX, up = INT_MAX;
    if(j-1 >= 0) left = solve(i, j-1, grid, dp);
    if(i-1 >= 0) up = solve(i-1, j, grid, dp);
    return dp[i][j] = grid[i][j] + min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, grid, dp);
}
*/

/*solution 4: recursion
int solve(int i, int j, vector<vector<int>>&grid) {
    if(i==0 && j==0) return grid[i][j];
    int left = INT_MAX, up = INT_MAX;
    if(j-1 >= 0) left = solve(i, j-1, grid);
    if(i-1 >= 0) up = solve(i-1, j, grid);
    return grid[i][j] + min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    return solve(n-1, m-1, grid);
}
*/
