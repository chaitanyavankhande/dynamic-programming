// Link:  https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650 

//tabulation space optimized - iterative solution
//TC: O(n)
// SC: O(1)


#include <bits/stdc++.h> 
using namespace std;
#define MOD int(1e9 + 7)

//tabulation solution
int countDistinctWays(int n) {
  //  Write your code here.
    if(n == 0) return 1;
    if(n <= 2) return n;

    int first = 1, second = 1, current;

    for(int i=2; i<=n; i++) {
        current = (first + second) % MOD;
        first = second;
        second = current;
    }
    return current;
}
