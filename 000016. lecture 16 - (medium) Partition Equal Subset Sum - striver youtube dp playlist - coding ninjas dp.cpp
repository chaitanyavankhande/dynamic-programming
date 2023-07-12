

// https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980

/* solution 1: tabulation space optimized */
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	if(allSum % 2 == 1) return false;

	int target = allSum / 2;
	vector<bool> current(target+1, false), previous(target+1, false);
	previous[0] = true;
	
	for(int i=1; i<=n; i++) {
		current[0] = true;
		for(int j=1; j<=target; j++) {
			bool pick = false;
			if(j >= arr[i-1]) pick = previous[j - arr[i-1]];
			
			bool notPick = previous[j];
			current[j] = pick || notPick;
		}
		previous = current;
	}
	return previous[target];
}

/* solution 2: tabulation */
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	if(allSum % 2 == 1) return false;

	int target = allSum / 2;
	vector<vector<bool>> tb(n+1, vector<bool>(target+1, false));
	tb[0][0] = true;
	for(int i=1; i<=n; i++) {
		tb[i][0] = true;
		for(int j=1; j<=target; j++) {
			bool pick = false;
			if(j >= arr[i-1]) pick = tb[i-1][j - arr[i-1]];
			
			bool notPick = tb[i-1][j];
			tb[i][j] = pick || notPick;
		}
	}
	return tb[n][target];
}



/* solution 3: memoization */
bool solve(vector<int>&arr, int n, int target, vector<vector<int>>&dp) {
	if(target == 0) return true;
	if(n == 0) return false;
	
	if(dp[n][target] != -1) return dp[n][target];
	bool pick = false;
	if(target >= arr[n-1]) pick = solve(arr, n-1, target - arr[n-1], dp);
	if(pick) return true;
	
	bool notPick = solve(arr, n-1, target, dp);
	return dp[n][target] = notPick;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	if(allSum % 2 == 1) return false;

	int target = allSum / 2;
	vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
	
	return solve(arr, n, target, dp);
}

/* solution 4: recursion */
bool solve(vector<int>&arr, int n, int target) {
	if(target == 0) return true;
	if(n == 0) return false;
	
	bool pick = false;
	if(target >= arr[n-1]) pick = solve(arr, n-1, target - arr[n-1]);
	if(pick) return true;
	
	bool notPick = solve(arr, n-1, target);
	return notPick;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	if(allSum % 2 == 1) return false;
	return solve(arr, n, allSum / 2);
}
