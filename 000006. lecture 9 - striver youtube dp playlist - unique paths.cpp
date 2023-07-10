// https://www.codingninjas.com/studio/problems/total-unique-paths_1081470

#include <bits/stdc++.h> 
//  solution 1: tabulation space optimization
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> previous(n+1, 0), current(n+1, 0);
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1 && j==1) current[j] = 1;
			else current[j] = previous[j] + current[j-1];

			previous = current;
		}
	}
	return current[n];
}

/* solution 2: tabulation
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>tb(m+1, vector<int>(n+1, 0));

	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1 && j==1) tb[i][j] = 1;
			else tb[i][j] = tb[i-1][j] + tb[i][j-1];
		}
	}
	return tb[m][n];
}
*/

/*solution 3: memoization
int solve(int i, int j, vector<vector<int>>&dp) {
	if(i==1 && j==1) return 1;
	if(i==0 || j==0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = solve(i-1, j, dp) + solve(i, j-1, dp);
}

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
	return solve(m, n, dp);
}
*/

/*solution 4: recursion
int solve(int i, int j) {
	if(i==1 && j==1) return 1;
	if(i==0 || j==0) return 0;
	return solve(i-1, j) + solve(i, j-1);
}

int uniquePaths(int m, int n) {
	// Write your code here.
	return solve(m, n);
}
*/
