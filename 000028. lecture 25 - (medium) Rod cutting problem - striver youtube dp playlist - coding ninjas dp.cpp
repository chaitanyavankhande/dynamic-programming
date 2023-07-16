
// https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284

//n = size of rod, also n = size of price vector

/* solution 1: tabulation space optimized */
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int rodLength = n;
	vector<int> previous(rodLength+1, 0), current(rodLength+1, 0);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=rodLength; j++) {
			int cut = 0;
			if(j>=i) cut = price[i-1] + current[j-i];
			int notCut = previous[j];
			current[j] = max(cut, notCut);
		}
		previous = current;
	}
	return previous[n];
}

/* solution 2: tabulation */
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int rodLength = n;
	vector<vector<int>> tb(n+1, vector<int>(rodLength+1, 0));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=rodLength; j++) {
			int cut = 0;
			if(j>=i) cut = price[i-1] + tb[i][j-i];
			int notCut = tb[i-1][j];
			tb[i][j] = max(cut, notCut);
		}
	}
	return tb[n][n];
}

/* solution 3: memoization */
int solve(vector<int>&price, int n, int rodLength, vector<vector<int>>&dp) {
	
	if(rodLength == 0) return 0;
	if(n == 0) return 0;
	if(dp[n][rodLength] != -1) return dp[n][rodLength];
	int cut = 0;
	if(rodLength>=n) cut = price[n-1] + solve(price, n, rodLength-n, dp);
	int notCut = solve(price, n-1, rodLength, dp);
	return dp[n][rodLength] = max(cut, notCut);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	return solve(price, n, n, dp);
}


/* solution 4: recursion */
int solve(vector<int>&price, int n, int rodLength) {
	
	if(rodLength == 0) return 0;
	if(n == 0) return 0;
	int cut = 0;
	if(rodLength>=n) cut = price[n-1] + solve(price, n, rodLength-n);
	int notCut = solve(price, n-1, rodLength);
	return max(cut, notCut);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	return solve(price, n, n);
}

