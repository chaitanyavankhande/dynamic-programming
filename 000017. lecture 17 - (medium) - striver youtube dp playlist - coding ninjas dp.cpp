
// https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h> 

/* solution 1: tabulation space optimized */
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	vector<int> current(allSum+1, INT_MAX), previous(allSum+1, INT_MAX);
	
	for(int j=0; j<=allSum; j++) {
		int part2Sum = allSum - j;
		int currentDiff = abs(j - part2Sum);
		previous[j] = currentDiff;
	}

	for(int i=1; i<=n; i++) {
		for(int j=allSum; j>=0; j--) {
			int part2Sum = allSum - j;
			int currentDiff = abs(j - part2Sum);
			
            int pick = INT_MAX;
			if(j + arr[i-1] <= allSum) pick = previous[j + arr[i-1]];
			int notPick = previous[j];

			current[j] = min(currentDiff, min(pick, notPick));
		}
		previous = current;
	}
	return previous[0];
}


/* solution 2: tabulation */
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int allSum = 0;
    for (int i = 0; i < n; i++) allSum += arr[i];
    vector<vector<int>> tb(n+1, vector<int>(allSum+1, INT_MAX));
    
    for (int j = 0; j <= allSum; j++) {
        int part2Sum = allSum - j;
        int currentDiff = abs(j - part2Sum);
        tb[0][j] = currentDiff;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = allSum; j >= 0; j--) {
            int part2Sum = allSum - j;
            int currentDiff = abs(j - part2Sum);

            int pick = INT_MAX;
			if(j + arr[i-1] <= allSum) pick = tb[i-1][j + arr[i-1]];
            int notPick = tb[i-1][j];

            tb[i][j] = min(currentDiff, min(pick, notPick));
        }
    }
    
    return tb[n][0];
}



/* solution 3: memoization */
int solve(vector<int>&arr, int n, int part1Sum, int allSum, vector<vector<int>>&dp) {
	
	int part2Sum = allSum - part1Sum;
	int currentDiff = abs(part1Sum - part2Sum);
	if(n == 0) return currentDiff;
	
	if(dp[n][part1Sum] != -1) return dp[n][part1Sum];
	int pick = solve(arr, n-1, part1Sum + arr[n-1], allSum, dp);
	int notPick = solve(arr, n-1, part1Sum, allSum, dp);

	return dp[n][part1Sum] = min(currentDiff, min(pick, notPick));	
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	vector<vector<int>> dp(n+1, vector<int>(allSum+1, -1));
	return solve(arr, n, 0, allSum, dp);
}


/* solution 4: recursion */
int solve(vector<int>&arr, int n, int part1Sum, int allSum) {
	
	int part2Sum = allSum - part1Sum;
	int currentDiff = abs(part1Sum - part2Sum);
	if(n == 0) return currentDiff;

	int pick = solve(arr, n-1, part1Sum + arr[n-1], allSum);
	int notPick = solve(arr, n-1, part1Sum, allSum);

	return min(currentDiff, min(pick, notPick));

	
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	return solve(arr, n, 0, allSum);
}
