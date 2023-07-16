

// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 

/* solution 1: tabulation space optimized */
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> current(maxWeight+1, 0), previous(maxWeight+1, 0);
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=maxWeight; j++) {
			int pick = 0;
			if(j >= weight[i-1]) pick = value[i-1] + previous[j-weight[i-1]];
			int notPick = previous[j];
			current[j] = max(pick, notPick);			
		}
		previous = current;
	}
	return current[maxWeight];
}

/* solution 2: tabulation */
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>tb(n+1, vector<int>(maxWeight+1, 0));
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=maxWeight; j++) {
			int pick = 0;
			if(j >= weight[i-1]) pick = value[i-1] + tb[i-1][j-weight[i-1]];
			int notPick = tb[i-1][j];
			tb[i][j] = max(pick, notPick);			
		}
	}
	return tb[n][maxWeight];
}


/* solution 3: memoization */
int solve(vector<int>&weight, vector<int>&value, int n, int maxWeight,
vector<vector<int>>&dp) {
	
	if(n == 0) return 0;
	if(dp[n][maxWeight] != -1) return dp[n][maxWeight];
	int pick = 0;
	if(maxWeight >= weight[n-1]) pick = value[n-1] + solve(weight, value, n-1, maxWeight-weight[n-1], dp);
	int notPick = solve(weight, value, n-1, maxWeight, dp);
	return dp[n][maxWeight] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n+1, vector<int>(maxWeight+1, -1));
	return solve(weight, value, n, maxWeight, dp);
}


/* solution 4: recursion */
int solve(vector<int>&weight, vector<int>&value, int n, int maxWeight) {
	
	if(n == 0) return 0;
	int pick = 0;
	if(maxWeight >= weight[n-1]) pick = value[n-1] + solve(weight, value, n-1, maxWeight-weight[n-1]);
	int notPick = solve(weight, value, n-1, maxWeight);
	return max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solve(weight, value, n, maxWeight);
}
