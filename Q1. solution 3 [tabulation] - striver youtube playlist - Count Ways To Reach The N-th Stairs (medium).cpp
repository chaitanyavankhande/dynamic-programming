// Link:  https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650 

//tabulation - iterative solution
//TC: O(n)
// SC: O(n)


#include <bits/stdc++.h> 
using namespace std;
#define MOD int(1e9 + 7)

//tabulation solution
int countDistinctWays(int n) {
  //  Write your code here.
    vector<int>tb(n+1, 0);
    tb[0] = 1;
    for(int i=1; i<=n; i++) {
        if(i-2 >= 0) {
            tb[i] = (tb[i-1] + tb[i-2]) % MOD;
        }
        else {
            tb[i] = tb[i-1] % MOD;
        }
    }
    return tb[n];
}
