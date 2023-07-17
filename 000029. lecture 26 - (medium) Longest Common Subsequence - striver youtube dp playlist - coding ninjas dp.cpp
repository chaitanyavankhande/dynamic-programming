
// https://www.codingninjas.com/studio/problems/longest-common-subsequence_1063255

#include <bits/stdc++.h> 

/* solution 1: tabulation space optimized */
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int n1 = str1.size(), n2 = str2.size();
  vector<int> previous(n2+1, 0), current(n2+1, 0);
  for(int i=1; i<=n1; i++) {
    for(int j=1; j<=n2; j++) {
      if(str1[i-1] == str2[j-1]) {
        int both = 0;
        both = 1 + previous[j-1];
        current[j] = both;
      }
      else {
        int first = current[j-1];
        int second = previous[j];
        current[j] = max(first, second);
      }
    }
    previous = current;
  }
  return previous[n2];
}


/* solution 2: tabulation */
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int n1 = str1.size(), n2 = str2.size();
  vector<vector<int>> tb(n1+1, vector<int>(n2+1, 0));
  for(int i=1; i<=n1; i++) {
    for(int j=1; j<=n2; j++) {
      if(str1[i-1] == str2[j-1]) {
        int both = 0;
        both = 1 + tb[i-1][j-1];
        tb[i][j] = both;
      }
      else {
        int first = tb[i][j-1];
        int second = tb[i-1][j];
        tb[i][j] = max(first, second);
      }
    }
  }
  return tb[n1][n2];
}



/* solution 3: memoization */
int solve(string &str1, int n1, string &str2, int n2, vector<vector<int>>&dp) {
  if(n1 == 0 || n2 == 0) return 0;
  if(dp[n1][n2] != -1) return dp[n1][n2];
  int both = 0;
  if(str1[n1-1] == str2[n2-1]) {
    both = 1 + solve(str1, n1-1, str2, n2-1, dp);
    return both;
  }
  int first = solve(str1, n1, str2, n2-1, dp);
  int second = solve(str1, n1-1, str2, n2, dp);
  return dp[n1][n2] = max(both, max(first, second));
}
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int n1 = str1.size(), n2 = str2.size();
  vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
  return solve(str1, n1, str2, n2, dp);
}



/* solution 4: recrusion */
int solve(string &str1, int n1, string &str2, int n2) {
  if(n1 == 0 || n2 == 0) return 0;
  int both = 0;
  if(str1[n1-1] == str2[n2-1]) {
    both = 1 + solve(str1, n1-1, str2, n2-1);
    return both;
  }
  int first = solve(str1, n1, str2, n2-1);
  int second = solve(str1, n1-1, str2, n2);
  return max(both, max(first, second));
}
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  return solve(str1, str1.size(), str2, str2.size());
}
