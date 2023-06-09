// Link:  https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650 

//tabulation - iterative solution
//TC: O(n)
// SC: O(n)

//method 1
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

//method 2
#include <bits/stdc++.h> 
using namespace std;
#define MOD int(1e9 + 7)

//tabulation solution
int countDistinctWays(int n) {
  //  Write your code here.
    if(n == 0) return 1;
    if(n <= 2) return n;

    vector<int>tb(n+1, 0);
    tb[0] = 1;
    tb[1] = 1;
    for(int i=2; i<=n; i++) {
        tb[i] = (tb[i-1] + tb[i-2]) % MOD;
    }
    return tb[n];
}
