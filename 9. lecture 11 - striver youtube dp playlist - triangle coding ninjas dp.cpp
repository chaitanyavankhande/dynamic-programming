

#include <bits/stdc++.h> 

// solution 1: tabulation space optimized
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	if(n==1) return triangle[0][0];
	vector<int>current(n), next(n);
	
	for(int i=n-1; i>=0; i--) {
		for(int j=i; j>=0; j--) {
			if(i == n-1) current[j] = triangle[i][j];
			else {
				current[j] = 
				triangle[i][j] + 
				min(
					next[j],
					next[j+1]
				);
			}
		}
		next = current;
		current.pop_back();
	}
	return next[0];
}

/* solution 2: tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> tb;
	for(int i=1; i<=n; i++) {
		vector<int> v(i, -1);
		tb.push_back( v );
	}
	
	for(int i=n-1; i>=0; i--) {
		for(int j=i; j>=0; j--) {
			if(i == n-1) tb[i][j] = triangle[i][j];
			else {
				tb[i][j] = 
				triangle[i][j] + 
				min(
					tb[i+1][j],
					tb[i+1][j+1]
				);
			}
		}
	}
	return tb[0][0];
}
*/

/*
int solve(int i, int j, vector<vector<int>>&triangle, vector<vector<int>>&dp) {
	
	int n = triangle.size();
	if(i == n-1) return triangle[i][j];

	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = 
		triangle[i][j] + 
		min(
			solve(i+1, j, triangle, dp), 
			solve(i+1, j+1, triangle, dp)
		);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp;
	for(int i=1; i<=n; i++) {
		vector<int> v(i, -1);
		dp.push_back( v );
	}
	return solve(0, 0, triangle, dp);
}
*/


/*solution 4: recursion
int solve(int i, int j, vector<vector<int>>&triangle) {
	
	int n = triangle.size();
	if(i == n-1) return triangle[i][j];
	return triangle[i][j] + min(solve(i+1, j, triangle), solve(i+1, j+1, triangle));
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return solve(0, 0, triangle);
}
*/
