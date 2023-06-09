// Link:  https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650 

//recursion solution
//TC: O(2^n)
// SC: O(1)

#include <bits/stdc++.h> 
using namespace std;
#define MOD int(1e9 + 7)

//recursion
int solve(int n) {
    if(n <= 0) return n+1; // n=0 -> return 1; n=-1 => returns 0;
    return (solve(n-1) + solve(n-2)) % MOD;
}

int countDistinctWays(int n) {
    return solve(n);
}
