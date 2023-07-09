// https://www.codingninjas.com/studio/problems/unique-paths-ii_977241


#define MOD int(1e9 + 7)
//solution 1: tabulation space optimized
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    if(mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    vector<int>previous(m, 0), current(m, 0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) current[j] = 1;
            else if(mat[i][j] == -1) current[j] = 0;
            else {
                int left=0, up=0;
                if(i-1 >= 0) left = previous[j];
                if(j-1 >= 0) up = current[j-1];
                current[j] = (left % MOD + up % MOD) % MOD;
            }
        }
        previous = current;
    }
    return current[m-1];
}

/* solution 2: tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    if(mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    vector<vector<int>>tb(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) tb[i][j] = 1;
            else if(mat[i][j] == -1) tb[i][j] = 0;
            else {
                int left=0, up=0;
                if(i-1 >= 0) left = tb[i-1][j];
                if(j-1 >= 0) up = tb[i][j-1];
                tb[i][j] = (left % MOD + up % MOD) % MOD;
            }
        }
    }
    return tb[n-1][m-1];
}
*/


/*solution 3: memoization
int solve(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp) {
    
    if(i<0 || j<0) return 0;
    if(mat[i][j] == -1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (solve(i-1, j, mat, dp)%MOD + solve(i, j-1, mat, dp)%MOD)%MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    if(mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    vector<vector<int>>dp(n, vector<int>(m, -1));
    
    return solve(n-1, m-1, mat, dp);   
}
*/

/*solution 4: recursion
int solve(int i, int j, vector<vector<int>>&mat) {
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(mat[i][j] == -1) return 0;
    return (solve(i-1, j, mat)%MOD + solve(i, j-1, mat)%MOD)%MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    if(mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    return solve(n-1, m-1, mat);   
}
*/
