// https://www.codingninjas.com/studio/problems/longest-common-substring_1235207

#include <bits/stdc++.h> 

/* using 2d array instead of 2d vector for better speed */
int lcs(string &str1, string &str2) {
	//	Write your code here.
	int longestSubStr = 0;
	int n1 = str1.size(), n2 = str2.size();
	int tb[n1+1][n2+1];
	memset(tb, 0, sizeof(tb));
	for(int i=1; i<=n1; i++) {
		for(int j=1; j<=n2; j++) {
			if(str1[i-1] == str2[j-1]) {
				tb[i][j] = 1 + tb[i-1][j-1];
				longestSubStr = max(longestSubStr, tb[i][j]);
			}
		}
	}
	return longestSubStr;
}

/* solution 1: tabulation space optimized */
int lcs(string &str1, string &str2) {
	//	Write your code here.
	int longestSubStr = 0;
	int n1 = str1.size(), n2 = str2.size();
	vector<int>previousVect(n2+1, 0), currentVect(n2+1, 0);
	for(int i=1; i<=n1; i++) {
		for(int j=1; j<=n2; j++) {
			int current = 0;
			if(str1[i-1] == str2[j-1]) {
				current = 1 + previousVect[j-1];
				longestSubStr = max(longestSubStr, current);
			}
			currentVect[j] = current;
		}
		previousVect = currentVect;
	}
	return longestSubStr;
}


/* solution 2: tabulation */
int lcs(string &str1, string &str2) {
	//	Write your code here.
	int longestSubStr = 0;
	int n1 = str1.size(), n2 = str2.size();
	vector<vector<int>> tb(n1+1, vector<int>(n2+1, 0));
	
	for(int i=1; i<=n1; i++) {
		for(int j=1; j<=n2; j++) {
			int current = 0;
			if(str1[i-1] == str2[j-1]) {
				current = 1 + tb[i-1][j-1];
				longestSubStr = max(longestSubStr, current);
			}
			tb[i][j] = current;
		}
	}
	return longestSubStr;
}



/* solution 3: memoization */
int solve(string &str1, int n1, string str2, int n2, int &longestSubStr, vector<vector<int>>&dp) {
	if(n1 == 0 || n2 == 0) return 0;
	if(dp[n1][n2] != -1) return dp[n1][n2];
	int current = 0;
	if(str1[n1-1] == str2[n2-1]) {
		current = 1 + solve(str1, n1-1, str2, n2-1, longestSubStr, dp);
		longestSubStr = max(longestSubStr, current);
	}
	
	solve(str1, n1, str2, n2-1, longestSubStr, dp);
	solve(str1, n1-1, str2, n2, longestSubStr, dp);
	
	return dp[n1][n2] = current;
}

int lcs(string &str1, string &str2) {
	//	Write your code here.
	int longestSubStr = 0;
	int n1 = str1.size(), n2 = str2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
	solve(str1, n1, str2, n2, longestSubStr, dp);
	return longestSubStr;
}


/* solution 4: recursion */
int solve(string &str1, int n1, string str2, int n2, int &longestSubStr) {
	if(n1 == 0 || n2 == 0) return 0;

	int current = 0;
	if(str1[n1-1] == str2[n2-1]) {
		current = 1 + solve(str1, n1-1, str2, n2-1, longestSubStr);
		longestSubStr = max(longestSubStr, current);
	} 
	
	solve(str1, n1, str2, n2-1, longestSubStr);
	solve(str1, n1-1, str2, n2, longestSubStr);
	
	return current;
}

int lcs(string &str1, string &str2) {
	//	Write your code here.
	int longestSubStr = 0;
	int n1 = str1.size(), n2 = str2.size();
	solve(str1, n1, str2, n2, longestSubStr);
	return longestSubStr;
}

