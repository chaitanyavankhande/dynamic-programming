
// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532

#define MOD int(1e9+7)
/* solution 1: tabulation space optimized */
int findWays(vector<int>& arr, int target)
{
	// Write your code here.
    int n = arr.size();
    vector<int>current(target+1, 0), previous(target+1, 0);
    previous[0] = 1;
    for(int i=1; i<=n; i++) {
        current[0] = 1;
        for(int j=0; j<=target; j++) {
            int pick = 0;
            if(j >= arr[i-1]) pick = previous[j - arr[i-1]];
            int notPick = previous[j];
            current[j] = (pick%MOD + notPick%MOD)%MOD;
        }
        previous = current;
    }
    return previous[target];
}


/* solution 2: tabulation */
int findWays(vector<int>& arr, int target)
{
	// Write your code here.
    int n = arr.size();
    vector<vector<int>> tb(n+1, vector<int>(target+1, 0));
    tb[0][0] = 1;
    for(int i=1; i<=n; i++) {
        tb[i][0] = 1;
        for(int j=0; j<=target; j++) {
            int pick = 0;
            if(j >= arr[i-1]) pick = tb[i-1][j - arr[i-1]];
            int notPick = tb[i-1][j];
            tb[i][j] = (pick%MOD + notPick%MOD)%MOD;
        }
    }
    return tb[n][target];
}


/* solution 3: memoization */
int solve(vector<int>&arr, int target, int n, vector<vector<int>>&dp) {
    
    if(n == 0) return target==0;
    if(dp[n][target] != -1) return dp[n][target];
    int pick = 0;
    if(target >= arr[n-1]) pick = solve(arr, target - arr[n-1], n-1, dp);
    int notPick = solve(arr, target, n-1, dp);
    return dp[n][target] = (pick%MOD + notPick%MOD)%MOD;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return solve(arr, k, n, dp);
}



/* solution 4: recursion */
int solve(vector<int>&arr, int target, int n) {
    
    if(n == 0) return target==0;
    int pick = 0;
    if(target >= arr[n-1]) pick = solve(arr, target - arr[n-1], n-1);
    int notPick = solve(arr, target, n-1);
    return (pick%MOD + notPick%MOD)%MOD;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
    return solve(arr, k, n);
}
