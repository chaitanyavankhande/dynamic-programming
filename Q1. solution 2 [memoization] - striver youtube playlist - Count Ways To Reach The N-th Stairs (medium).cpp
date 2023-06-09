// Link:  https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650 

//memoization - optimized recursion solution
//TC: O(n)
//SC: O(n)



#include <bits/stdc++.h> 
using namespace std;
#define MOD int(1e9 + 7)


//dp solution
int solve(int n, vector<int> &dp) {
    if(n <= 0) return n+1; // n=0 -> return 1; n=-1 => returns 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % MOD;
}

int countDistinctWays(int n) {
  //  Write your code here.
  vector<int>dp(n+1, -1);
  return solve(n, dp);
}
