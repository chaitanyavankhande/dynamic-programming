

// solution 1: tabluation space optimization (part1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>previous(3, -1), current(3, -1);
    for(int i=0; i<3; i++) previous[i] = points[0][i];


    for(int i=1; i<n; i++) {
        for(int j=0; j<3; j++) {
            int maxMerits = -1;
            for(int k=0; k<3; k++) {
                if(k==j) continue;
                maxMerits = max(maxMerits, previous[k]);
            }
            current[j] = points[i][j] + maxMerits;
        }
        previous = current;
    }
    return max(current[0], max(current[1], current[2]));
}


/* solution 1: tabluation space optimization (part2)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.    
    vector<int>previous(3, -1), current(3, -1);

    for(int i=0; i<3; i++) previous[i] = points[0][i];

    for(int i=1; i<n; i++) {
        current[0] = points[i][0] + max(previous[1], previous[2]);
        current[1] = points[i][1] + max(previous[0], previous[2]);
        current[2] = points[i][2] + max(previous[0], previous[1]);
        previous = current;
    }
    return max(current[0], max(current[1], current[2]));
}
*/

/*solution 2:tabulation (part1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> tb(n, vector<int>(3, -1));
    
    for(int i=0; i<3; i++) tb[0][i] = points[0][i];

    for(int i=1; i<n; i++) {
        for(int j=0; j<3; j++) {
            int maxMerits = -1;
            for(int k=0; k<3; k++) {
                if(k==j) continue;
                maxMerits = max(maxMerits, tb[i-1][k]);
            }
            tb[i][j] = points[i][j] + maxMerits;
        }
    }
    return max(tb[n-1][0], max(tb[n-1][1], tb[n-1][2]));
}
*/


/*solution 2: tabulation (part2)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> tb(n, vector<int>(3, -1));
    
    for(int i=0; i<3; i++) tb[0][i] = points[0][i];

    for(int i=1; i<n; i++) {
        tb[i][0] = points[i][0] + max(tb[i-1][1], tb[i-1][2]);
        tb[i][1] = points[i][1] + max(tb[i-1][0], tb[i-1][2]);
        tb[i][2] = points[i][2] + max(tb[i-1][0], tb[i-1][1]);
    }
    return max(tb[n-1][0], max(tb[n-1][1], tb[n-1][2]));

}
*/

/*solution 3: memoization
int solve(int n, vector<vector<int>> &points, int previous, vector<vector<int>>&dp) {
    if(n < 0) return 0;
    if(dp[n][previous] != -1) return dp[n][previous];
    int maxMerits = -1;
    for(int i=0; i<3; i++) {
        if(i == previous) continue;
        int merits = points[n][i] + solve(n-1, points, i, dp);
        maxMerits = max(maxMerits, merits);
    }
    return dp[n][previous] = maxMerits;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int maxMerits = -1;
    vector<vector<int>> dp(n, vector<int>(3, -1));
    for(int i=0; i<3; i++) {
        int merits = points[n-1][i] + solve(n-2, points, i, dp);
        maxMerits = max(maxMerits, merits);
    }
    return maxMerits;
}
*/



/* solution 4: recursion
int solve(int n, vector<vector<int>> &points, int previous) {
    if(n < 0) return 0;
    int maxMerits = -1;
    for(int i=0; i<3; i++) {
        if(i == previous) continue;
        int merits = points[n][i] + solve(n-1, points, i);
        maxMerits = max(maxMerits, merits);
    }
    return maxMerits;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int maxMerits = -1;
    for(int i=0; i<3; i++) {
        int merits = points[n-1][i] + solve(n-2, points, i);
        maxMerits = max(maxMerits, merits);
    }
    return maxMerits;

}
*/
