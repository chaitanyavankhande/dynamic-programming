// https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998

#include <bits/stdc++.h> 
// solution 1: tabulation space optimized
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<int>current(m,0), previous(m,0);

    for(int j=0; j<m; j++) previous[j] = current[j] = matrix[0][j];
    // if we dont consider current[j] in above statement, test cases having 1 row fail
    //eg: t=1, n=1, matrix[1][1] = {{-1000}}; o/p: 0 which should be -1000
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int up = INT_MIN, upLeft = INT_MIN, upRight = INT_MIN;
            up = previous[j];
            if(j-1 >= 0) upLeft = previous[j-1];
            if(j+1 < m) upRight = previous[j+1];
            current[j] = matrix[i][j] + max(up, max(upLeft, upRight));
        }
        previous = current;
    }
    
    int maxSum = INT_MIN;
    for(int j=0; j<m; j++) {
        int sum = current[j];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

/* solution 2: tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> tb(n, vector<int>(m, -1));

    for(int j=0; j<m; j++) tb[0][j] = matrix[0][j];
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int up = INT_MIN, upLeft = INT_MIN, upRight = INT_MIN;
            up = tb[i-1][j];
            if(j-1 >= 0) upLeft = tb[i-1][j-1];
            if(j+1 < m) upRight = tb[i-1][j+1];
            tb[i][j] = matrix[i][j] + max(up, max(upLeft, upRight));
        }
    }
    
    int maxSum = INT_MIN;
    for(int j=0; j<m; j++) {
        int sum = tb[n-1][j];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
*/

/* solution 3: memoization
int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp) {
    if(i==0) return matrix[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int n = matrix.size(), m = matrix[0].size();
    int up = INT_MIN, upLeft = INT_MIN, upRight = INT_MIN;
    up = solve(i-1, j, matrix, dp);
    if(j-1 >= 0) upLeft = solve(i-1, j-1, matrix, dp);
    if(j+1 < m) upRight = solve(i-1, j+1, matrix, dp);
    return dp[i][j] = matrix[i][j] + max(up, max(upLeft, upRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxSum = INT_MIN;
    for(int j=0; j<m; j++) {
        int sum = solve(n-1, j, matrix, dp);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
*/

/* solution 4: recursion
int solve(int i, int j, vector<vector<int>>&matrix) {
    if(i==0) return matrix[i][j];
    int n = matrix.size(), m = matrix[0].size();
    int up = INT_MIN, upLeft = INT_MIN, upRight = INT_MIN;
    up = solve(i-1, j, matrix);
    if(j-1 >= 0) upLeft = solve(i-1, j-1, matrix);
    if(j+1 < m) upRight = solve(i-1, j+1, matrix);
    return matrix[i][j] + max(up, max(upLeft, upRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    int maxSum = INT_MIN;
    for(int j=0; j<m; j++) {
        int sum = solve(n-1, j, matrix);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
*/
